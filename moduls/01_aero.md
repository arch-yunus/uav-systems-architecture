# Modül 1: Temeller ve Uçuş Fiziği (Aero 101)

> **Felsefe:** Hangi tuşa basacağını bilmeden önce, uçurduğun şeyin neden uçtuğunu bil.

---

## 1.1 İHA Tipleri: Hangisi, Nerede Kullanılır?

| Tip | Mekanizma | Avantaj | Dezavantaj | Kullanım |
| :--- | :--- | :--- | :--- | :--- |
| **Multikopter** (Quad/Hex/Octo) | Birden fazla sabit perde | Dikey iniş kalkış, hassas hovering | Kısa menzil, verimsiz | Fotogrametri, ISR, FPV |
| **Sabit Kanat** | Sabit kanat, tahrik pervanesi | Uzun menzil, verimli | Pist/fırlatma gerekli, hovering yok | Büyük alan tarama, uzun görev |
| **VTOL** (Çevik Geçişli) | Multikopter kalkış + sabit kanat uçuş | İkisinin avantajı | Karmaşık, ağır | Lojistik, uzun görev+hassas iniş |

---

## 1.2 Dört Temel Kuvvet

Bir İHA'nın havada kalması için kuvvetler dengede olmalıdır:

```
         KALDIRMA (Lift) ↑
                │
SÜRÜKLENME ←───┼───→ İTKİ (Thrust)
(Drag)          │
         YERÇEKİMİ (Weight) ↓

HOVER: Kaldırma = Yerçekimi
İLERİ UÇUŞ: İtki > Sürüklenme
TIRMANIŞ: Kaldırma > Yerçekimi
```

---

## 1.3 Pervane Dinamikleri

### Hatve (Pitch) Nedir?
Pervanenin bir tam turda teorik olarak ilerlediği mesafedir (inç).

```
Pervane: 5x4x3
         ↑ ↑ ↑
         │ │ └─ Kanat sayısı (3 kanat)
         │ └─── Hatve: 4 inç/tur
         └───── Çap: 5 inç
```

### İtki - Çap - Devir İlişkisi
```
İtki ∝ Çap² × Devir²

→ Çapı 2x artır = İtkiyi ~4x artırır
→ Devrini 2x artır = İtkiyi ~4x artırır (ama güç 8x artar!)

Sonuç: Büyük yavaş pervane > Küçük hızlı pervane (verimlilik açısından)
```

### Akım ve Güç Hesabı
```python
# Örnek: Motor testi sırasında
guc_watt = voltaj_volt * akim_amper
# 14.8V × 20A = 296W

# Motor verimliliği
verimlilik = guc_watt / itki_gram
# Sağlıklı: < 5W/g, Kötü: > 8W/g
```

---

## 1.4 Pratik Görev

> **Görev 1-A:** Elimdeki pervane ve motorun veri sayfasını (datasheet) bul. Hover noktasındaki akımı tespit et. Bu akımla seçtiğin bataryanın teorik uçuş süresini hesapla. Hesabını `odevler/modul1/pervane_hesabi.md` dosyasına yaz.

---

*Sonraki → [Modül 2: Elektronik ve Güç Sistemleri](moduls/02_electronics.md)*
