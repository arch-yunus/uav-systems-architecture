# Modül 4: Yazılım ve Konfigürasyon (Soft 101)

> **Felsefe:** "PID değerlerini tahmin etme. Sistemi anla, ardından bir yön ayarla."

---

## 4.1 Firmware Ekosistemi

### Betaflight
- FPV yarış ve akrobatik uçuş için optimize edilmiş.
- Düşük gecikme (latency) önceliği → Stability ikincil.

### ArduPilot
- Tam otonom görev, waypoint, RTH desteği.
- Karmaşık sensor füzyonu (EKF3).

### PX4
- Daha modüler mimari. ROS2 ile native entegrasyon (uXRCE-DDS).

---

## 4.2 PID Döngüsü Mantığı

```
Hata = İstenen Değer (Setpoint) - Mevcut Değer

P (Oransal):   Anlık hatayı düzelt.      Fazla P → Salınım
I (İntegral):  Birikmiş hatayı düzelt.   Fazla I → Aşım
D (Türevsel):  Hata değişim hızını izle. Fazla D → Titreme

Motor_Komutu = Kp × Hata + Ki × ΣHata + Kd × (ΔHata/Δzaman)
```

| Semptom | Sebep | Çözüm |
| :--- | :--- | :--- |
| Sallanma | P çok yüksek | P'yi düşür |
| Setpointe ulaşamıyor | I çok düşük | I'yı artır |
| Titrek hareket | D çok yüksek | D'yi düşür |

---

## 4.3 SITL: Sahaya Çıkmadan Uçuş Testi

```bash
# ArduPilot SITL başlat
sim_vehicle.py -v ArduCopter --console --map

# Temel komutlar
> arm throttle
> takeoff 10
> mode RTL
```

---

## 4.4 Pratik Görev

> **Görev 4-A:** SITL'de Kalkış → 30m → Öne 50m → RTL uçuşu yap. Logu kaydet.

*← [Modül 3](03_fc_sensors.md) | Sonraki → [Modül 5](05_first_build.md)*
