# Modül 2: Elektronik ve Güç Sistemleri (Atölye 101)

> **Felsefe:** "Havya tutmayan mühendis, kalemi olmayan ressam gibidir." Bu modülün sonunda elinde iyi bir lehim bırakabileceksin.

---

## 2.1 Havya Ehliyeti: Doğru Lehim Nasıl Yapılır?

### Isı Ayarı
- **Lehim teli için:** 320–350°C
- **AWG12/14 güç kabloları için:** 350–380°C
- **SMD bileşenler için:** 280–310°C

### Adım Adım Lehim Prosedürü
```
1. Yüzeyi zımpara veya flux ile hazırla (oksit tabakasını kaldır)
2. Havyayı ve iş parçasını birlikte ısıt (ikisini de!)
3. Lehim telini havyaya değil, ÇALIŞMAYERİNE değdir
4. Lehim akarsa al havyayı → soğuma (3–5 saniye) → hareket ettirme
```

### Soğuk Lehim Nasıl Anlaşılır?
- **İyi lehim:** Parlak, pürüzsüz, konik şekil
- **Soğuk lehim:** Mat, granüler, top gibi
- **Yanmış lehim:** Koyulaşmış, kırılgan

---

## 2.2 Multimetre Kullanımı

### Temel Ölçümler
```
DC Voltaj: Kırmızı → Artı, Siyah → Eksi
AC Voltaj: Faz ve toprak arasında ölç
Direnç:    Bileşeni devreden çıkar, sonra ölç
Süreklilik (Buzzer): Kopuk kablo tespiti için
```

### Kısa Devre Tespiti
```bash
# Akım çekmeden önce smoke stopper kullan!
# Smoke stopper yakarsa: bul ve düzelt
# Smoke stopper yanmıyorsa: güven ver
```

---

## 2.3 LiPo Batarya Anatomisi

```
4S 5000mAh 50C LiPo
│  │         │
│  │         └─ Maksimum deşarj = 50 × 5A = 250A
│  └─────────── Kapasite: 5000mAh (5Ah)
└───────────── Hücre sayısı: 4 hücre × 3.7V = 14.8V nominal

Tam şarj: 4 × 4.2V = 16.8V
Boş sınırı: 4 × 3.5V = 14.0V  ← İNMEYE BAŞLA
Zarar sınırı: 4 × 3.4V = 13.6V ← ASLA GEÇME
```

### Güvenli Saklama Kuralları
| Durum | Eylem |
| :--- | :--- |
| 1 haftadan az | Tam şarjta bırakabilirsin |
| 1 haftadan fazla | Storage voltajına indir (3.80–3.85V/hücre) |
| Şişmiş batarya | Kullanma. Kontrollü deşarj, sonra imha. |
| Şarj sırasında | Gözetimsiz bırakma. LiPo çantası kullan. |

---

## 2.4 BLDC Motor ve ESC Mantığı

```
Uçuş Bilgisayarı
      │
      │ DSHOT600 (Dijital)
      ↓
     ESC
      │
      │ 3 Fazlı AC (120° Aralarında)
      ↓
BLDC Motor
      │
      ↓
  DÖNER PERVANE
```

**ESC Kalibrasyonu Nedir?**
ESC, kumandanın tam gaz ve sıfır gaz sinyalini öğrenmesi gereken bir kalibrasyon prosedürüne ihtiyaç duyar. Kalibrasyon yapılmazsa motorlar farklı hızlarda başlar ve İHA stabil uçmaz.

---

## 2.5 Pratik Görev

> **Görev 2-A (Havya):** PDB (Güç Dağıtım Kartı) üzerine 4 adet AWG14 motor kablosunu bağla. Multimetre ile her konektörde voltaj olduğunu doğrula, kısa devre olmadığını teyit et. Fotoğrafı `odevler/modul2/lehim_fotograf.jpg` olarak ekle.

> **Görev 2-B:** Bataryanın hücre gerilimini multimetre ile ölç. Değerleri tabloya gir. 0.05V üstünde fark varsa nedenini araştır.

---

*← [Modül 1](01_aero.md) | Sonraki → [Modül 3: FC ve Sensörler](03_fc_sensors.md)*
