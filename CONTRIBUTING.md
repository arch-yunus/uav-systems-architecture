# 🤝 SUNGUR UAV Akademisi — Katkı Rehberi (Contributing Guide)

**Merhaba! Bu rehber, akademiye nasıl katkıda bulunabileceğini adım adım anlatır.**

---

## Nasıl Katkıda Bulunabilirim?

Aşağıdaki kategorilerde katkı kabul ediyoruz:

| Katkı Tipi | Örnek |
| :--- | :--- |
| 📝 Doküman | Ders notu, yanlış düzeltme, çeviri |
| 💻 Kod | Yeni ROS2 düğümü, simülatör özelliği, algoritma |
| 🐛 Hata Bildirimi | Yanlış formül, çalışmayan kod, kırık link |
| 💡 Öneri | Yeni ders konusu, lab fikri |

---

## Adım Adım Katkı

### 1. Repoyu Fork Et
GitHub'da **Fork** butonuna tıkla. Kendi hesabında bir kopya oluşacak.

### 2. Klonla ve Branch Aç
```bash
git clone https://github.com/<KULLANICI_ADIN>/uav-systems-architecture.git
cd uav-systems-architecture

# Anlamlı bir branch adı seç
git checkout -b feature/lab-04-slam-basics
```

### 3. Değişikliklerini Yap
- Yeni ders notları için `docs/` klasörünü kullan.
- Yeni ROS2 düğümleri için `src/<kategori>/` altına ekle.
- Her yeni düğümü `CMakeLists.txt`'e kaydet.

### 4. Test Et
```bash
# Kod değişikliği yaptıysan derle
cd ~/ros2_ws && colcon build --packages-select sungur_architecture
source install/setup.bash

# Markdown değişikliği yaptıysan link ve format kontrolü
# (markdownlint veya Prettier kullanabilirsin)
```

### 5. Commit ve Push
```bash
# Anlamlı commit mesajı kullan
git add .
git commit -m "feat(docs): Lab 04 - SLAM temelleri eklendi

- SLAM kavramı açıklandı
- RTAB-Map entegrasyonu gösterildi
- Pratik alıştırma soruları eklendi"

git push origin feature/lab-04-slam-basics
```

### 6. Pull Request Aç
GitHub'da Pull Request oluştur. Açıklama kısmına:
- Ne yaptığını
- Neden gerektiğini
- Nasıl test ettiğini

---

## Stil Rehberi

### Dokümanlar için:
- Her doküman `> **Amaç:**` bloğu ile başlar.
- Her modül `## 📝 Pratik Alıştırma` bölümüyle biter.
- Mermaid diyagramları için `\`\`\`mermaid` kullan.

### Kod için:
- C++: Google C++ Style Guide
- Python: PEP 8
- Her fonksiyon Türkçe açıklama satırı içerir.

---

## Sertifikasyon için Katkı

Pull Request'in merge edilmesi, sertifikasyon sürecinde "Açık Kaynak Katkısı" olarak değerlendirilir.

---

*Sorularınız için: GitHub Issues kullanın veya Akademi kanalına yazın.*

**Teşekkürler! Her katkı akademiyi daha güçlü yapar. ⚔️**
