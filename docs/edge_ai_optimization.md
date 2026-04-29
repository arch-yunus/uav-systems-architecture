# 👁️ Edge-AI ve Model Optimizasyonu

İHA üzerindeki kısıtlı kaynaklarla (SBC) gerçek zamanlı görüntü işleme yapmak için donanım hızlandırma şarttır.

## 1. TensorRT Optimizasyonu
Nvidia Jetson cihazlarında FP16 veya INT8 kuantizasyonu ile FPS değerlerini 3-5 kat artırmak mümkündür.
- **Workflow**: PyTorch Model -> ONNX -> TensorRT Engine.
- **Precision**: Görev kritik değilse INT8 kullanarak güç tüketimi azaltılabilir.

## 2. GStreamer Pipelines
CPU kullanımını %5'in altında tutmak için donanımsal dekoderler kullanılmalıdır.
- **Örnek Pipeline**: `v4l2src ! video/x-raw,format=NV12 ! nvv4l2h264enc ! rtph264pay ! udpsink`
- **Zero-Copy**: RAM üzerinde veri kopyalamadan doğrudan GPU belleğine erişim (NVMM).

## 3. Computer Vision Görevleri
- **Object Detection**: YOLOv8-Small / Tiny (Gerçek zamanlı hedef takibi).
- **V-SLAM**: GPS sinyalinin olmadığı ormanlık veya kapalı alanlarda stereoskopik görüntü ile navigasyon.

---
*Görmek yetmez, anlık olarak anlamlandırmak gerekir.*
