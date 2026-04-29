# 🤖 Lab 03: Edge AI ve TensorRT — İHA'da Gerçek Zamanlı Algı

> **Hedef:** YOLOv8 modelini TensorRT ile optimize et, `tensorrt_wrapper.py`'yi anla ve sahte görüntü üzerinde çıkarım (inference) yap.

---

## Bölüm 1: Neden Edge AI?

```
Bulut AI:     Görüntü → İnternet → Sunucu → Sonuç → İHA
               Gecikme: 200–500ms (kabul edilemez!)

Edge AI:      Görüntü → NVIDIA Orin (İHA üstünde) → Sonuç
               Gecikme: 5–20ms ✅
```

İHA'da gerçek zamanlı nesne tespiti için gecikme < 30ms olmalıdır.

---

## Bölüm 2: TensorRT Optimizasyon Pipeline

```
[PyTorch Model] → [ONNX Export] → [TensorRT Engine] → [Inference]

Adım 1: PyTorch → ONNX
python -c "
import torch
from ultralytics import YOLO
model = YOLO('yolov8n.pt')
model.export(format='onnx', imgsz=640)
"

Adım 2: ONNX → TensorRT (.engine)
trtexec --onnx=yolov8n.onnx \
        --saveEngine=uav_yolov8.engine \
        --fp16 \              # Yarı hassasiyet (2x hız artışı)
        --workspace=4096      # 4GB GPU belleği
```

### Kuantizasyon Etkileri

| Format | Doğruluk | Hız | Bellek |
| :--- | :--- | :--- | :--- |
| FP32 | En yüksek | 1x | 4 byte/ağırlık |
| FP16 | ~%1 düşük | ~2x | 2 byte/ağırlık |
| INT8 | ~%3 düşük | ~4x | 1 byte/ağırlık |

---

## Bölüm 3: `tensorrt_wrapper.py` Kod İncelemesi

Dosyayı aç: `src/perception/tensorrt_wrapper.py`

```python
# Bu satırın amacını açıkla:
host_mem = cuda.pagelocked_empty(size, dtype)
device_mem = cuda.mem_alloc(host_mem.nbytes)
```

**Cevap:** `pagelocked_empty` → Pinned Memory (CPU-GPU veri transferini hızlandırır).
`mem_alloc` → GPU belleği tahsis eder.

**İnceleme Soruları:**
1. `infer()` fonksiyonunda kaç adım var? Her adımı açıkla.
2. `stream.synchronize()` neden gerekli?
3. Birden fazla görüntüyü aynı anda işlemek için (batch inference) ne değişmeli?

---

## Bölüm 4: Dummy Inference (Donanımsız Test)

```python
# TensorRT yoksa bu script ile pipeline'ı test et
import numpy as np

def dummy_inference(frame_shape=(640, 640, 3)):
    """Gerçek TRT olmadan inference pipeline simülasyonu."""
    # Sahte giriş
    input_data = np.random.rand(*frame_shape).astype(np.float32)
    
    # Ön işleme (normalizasyon)
    input_normalized = input_data / 255.0
    input_chw = input_normalized.transpose(2, 0, 1)  # HWC → CHW
    
    # Sahte çıkış (8400 bbox × 84 sınıf = YOLOv8 formatı)
    output = np.random.rand(8400, 84).astype(np.float32)
    
    # Güven skoru filtresi
    confidence = output[:, 4]
    high_conf = output[confidence > 0.5]
    
    print(f"Tespit edilen nesne sayısı: {len(high_conf)}")
    return high_conf

dummy_inference()
```

---

## Bölüm 5: ROS2 Entegrasyonu

```python
# target_perception_node.py ile nasıl entegre olur?
# cv_bridge ile ROS2 görüntüsü → OpenCV → TensorRT

from cv_bridge import CvBridge
bridge = CvBridge()

def image_callback(msg):
    cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding='rgb8')
    # infer_engine.infer(cv_image) → Tespit sonuçları
    # Sonuçları /detections topic'ine publish et
```

**Ödev:**
1. `dummy_inference()` fonksiyonunu çalıştır.
2. Güven skoru eşiğini 0.3, 0.5, 0.8 olarak değiştir. Sonuç nasıl değişiyor?
3. `target_perception_node.py`'yi oku. `dummy_inference()` ile nasıl entegre edersin?

---

*Sonraki Lab → [Sistem Mimarisi Felsefesi](../docs/../uav-tech-manual/docs/philosophy.md)*
