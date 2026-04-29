# 🔥 HATALOG — "Ben de Bunu Yaptım" Koleksiyonu

> Bu repo "Bozarak Öğrenmek" felsefesini benimser.
> Bu dosya, atölye ve sahadaki en yaygın hataları belgeler — sen de yapacaksın,
> ama en azından neden yaptığını anlayarak yapacaksın.

---

## ⚡ Elektronik Hataları

### Hata #001: Smoke Test Atlamak
**Ne oldu:** İlk güç vermede tüm kabloları yaktı.
**Sebep:** Smoke stopper kullanmadan direkt bağladı.
**Öğreti:** Her yeni montajda smoke stopper şart. 10 dakika kurtarır, 10 saat tamir önler.

---

### Hata #002: Batarya Polaritesini Ters Bağlamak
**Ne oldu:** ESC'nin tamamı, bazı durumlarda FC de yandı.
**Sebep:** XT60 konektörü tersine zorlamayla bağlandı.
**Öğreti:** XT60 sadece bir yönde girer. Zorlamak gerekiyorsa — dur ve kontrol et.

---

### Hata #003: Soğuk Lehim
**Ne oldu:** İlk uçuşta motor aniden durdu.
**Sebep:** Motor kablosu soğuk lehimle bağlanmıştı. Vibrasyon söktü.
**Öğreti:** Parlak, konik, pürüzsüz = iyi lehim. Mat, granüler = kır ve yeniden yap.

---

### Hata #004: Bataryayı 3.4V Altına Düşürmek
**Ne oldu:** Batarya şişti, ertesi gün kullanılamaz hale geldi.
**Sebep:** "Biraz daha uçayım" diye inme sinyalini görmezden geldi.
**Öğreti:** FC alarm verince in. Tartışma yok.

---

## ✈️ Uçuş ve Konfigürasyon Hataları

### Hata #005: Motor Yönlerini Test Etmemek (Pervanelerle)
**Ne oldu:** Drone kalkışta takla attı.
**Sebep:** Motor yön testi pervane takılı halde yapıldı, yanlış motor ters döndü.
**Öğreti:** Motor yön testi ASLA pervane takılıyken yapılmaz. Önce propsuz test, onay sonra pervane.

---

### Hata #006: Failsafe Ayarlamamak
**Ne oldu:** RC bağlantısı kesildi, drone kayboldu.
**Sebep:** Failsafe hiç ayarlanmamıştı.
**Öğreti:** İlk uçuştan önce failsafe testi şart. RC'yi kapat, drone RTH yapıyor mu gör.

---

### Hata #007: RTH İrtifasını Düşük Bırakmak
**Ne oldu:** RTH sırasında drone bir ağaca çarptı.
**Sebep:** RTH irtifası 5m olarak bırakılmıştı.
**Öğreti:** RTH irtifası = bölgedeki en yüksek engel + güvenlik payı. Minimum 50m.

---

### Hata #008: Maiden Flight'ta Tam Gaz Vermek
**Ne oldu:** Drone kontrolden çıktı, düştü.
**Sebep:** İlk uçuşta PID ayarları bilinmiyordu, tam gaz verdi.
**Öğreti:** Maiden flight = hover testi. 1m irtifada stabiliteyi kontrol et, sonra yüksek.

---

## 💻 Yazılım Hataları

### Hata #009: PID Reset'i Unutmak
**Ne oldu:** Mod değişiminde drone ani bir hamle yaptı.
**Sebep:** Hover → RTH geçişinde `pid.reset()` çağrılmamıştı. Integral büyük birikimle patladı.
**Öğreti:** Her mod geçişinden önce PID'i sıfırla. → `src/gnc/pid_controller.hpp`

---

### Hata #010: SITL'siz Sahaya Çıkmak
**Ne oldu:** Yeni yazılım sahada çalışmadı, drone indi.
**Sebep:** Kod direkt sahada test edildi.
**Öğreti:** SITL → Bench Test → Saha. Bu sıralamayı atlama.

---

### Hata #011: GPS Fix Almadan Arm Etmek
**Ne oldu:** Drone GPS modunda drift etti ve bir duvara çarptı.
**Sebep:** GPS fix uyarısı görmezden gelindi.
**Öğreti:** GPS modu = GPS fix şart. Fix yoksa Stabilize/Acro modda uç veya beklir.

---

## 🌿 Saha Hataları

### Hata #012: Rüzgara Karşı Uçmak
**Ne oldu:** Drone geri dönemedi, batarya bitti, düştü.
**Sebep:** Rüzgar 12m/s iken platformun limiti olan 10m/s görmezden gelindi.
**Öğreti:** Rüzgar her zaman önce senden öğrenirsin, sonra drone'dan öğrenir.

---

### Hata #013: İzin Almadan Uçmak
**Ne oldu:** Para cezası + drone'a el konuldu.
**Sebep:** NFZ sınırı bilinmiyordu.
**Öğreti:** Her uçuş öncesi NOTAM sorgula. → `uav-mission-control/docs/regulations/law.md`

---

## 🤝 Katkı

"Ben de bunu yaptım" kategorisinde paylaşmak istediğin bir hata varsa PR gönder.
Fotoğraf, log ve açıklama ile birlikte. Utanma — herkese öğretir.
