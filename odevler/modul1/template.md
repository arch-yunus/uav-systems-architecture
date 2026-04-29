# Görev 1 — Pervane ve Motor Hesabı

> **Modül:** 1 — Temeller ve Uçuş Fiziği
> **Teslim:** Bu dosyayı doldur, `odevler/modul1/` altına ekle, PR gönder.

---

## Platformum

| Parametre | Değerim |
| :--- | :--- |
| Platform Tipi | (Multikopter / FPV / F450) |
| Şasi / Frame | |
| Motor | (Marka, Model, KV) |
| Pervane | (çap × hatve × kanat sayısı) |
| Batarya | (nS, kapasite mAh, C-rating) |
| Tahmini TOM | g |

---

## Hesaplamalar

### 1. Teorik Motor Devri
```
RPM = KV × Voltaj(nominal)
RPM = _____ × _____ = _____ devir/dak
```

### 2. İtki Tahmini (Teorik)
```
Hedef: Toplam itki ≥ 2 × TOM (güvenli hover marjı)

Motor başına hedef itki = (2 × TOM) / motor_sayısı
Motor başına hedef itki = ______g
```

### 3. Uçuş Süresi Tahmini
```python
# scripts/flight_calculator.py ile veya elle hesapla:
kapasite_mah = _____
ortalama_akim_a = _____   # Hover sırasında motor başına akım × motor sayısı
guvenlik_marji = 0.20     # %20

kullanilabilir_mah = kapasite_mah * (1 - guvenlik_marji)
ucus_suresi_dak = (kullanilabilir_mah / 1000) / ortalama_akim_a * 60

# Hesabın sonucu: _____ dakika
```

---

## Kaynaklar

Motor/pervane verilerini nereden buldun?
- [ ] Üretici veri sayfası (datasheet)
- [ ] Thrust stand ölçümü
- [ ] Tahmin / forum

---

## Öğrendiklerim

Bu görevi yaparken neyi öğrendim veya hangi sorum aklıma takıldı?

_Buraya yaz..._
