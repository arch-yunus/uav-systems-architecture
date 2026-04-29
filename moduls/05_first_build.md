# Modül 5: İlk Montaj ve Saha (Pratik 101)

> **Felsefe:** "Simülatör seni hazırlar, saha seni pişirir."

---

## 5.1 Montaj Öncesi Hazırlık

**Checklist:**
```
[ ] Tüm bileşenler eksiksiz mi?
[ ] Smoke Stopper hazır mı?
[ ] Multimetre şarjlı mı?
[ ] Çalışma masası temiz ve aydınlık mı?
[ ] LiPo güvenlik çantası hazır mı?
```

---

## 5.2 F450 Montaj Sırası

```
1. ŞASI: Alt plakayı monte et. Motor kollarını vida torku ile sabitle.
2. MOTORLAR: Her kola doğru dönüş yönünde motor yerleştir.
   CCW: Ön-Sol, Arka-Sağ
   CW:  Ön-Sağ, Arka-Sol
3. ESC: Her motora bir ESC. Kablo yönetimine dikkat et.
4. PDB/FC: Güç dağıtım kartını orta plakaya monte et.
5. KABLO: Motor → ESC → PDB → Batarya konektörü.
6. SMOKE TEST: Pervanesiz güç ver. Duman yok → Devam et.
7. FC BAĞLANTI: ESC sinyal kablolarını FC'ye bağla.
8. KALIBRASYON: ESC kalibrasyon + Motor yön testi (props olmadan!).
9. PERVANE: Doğru yöne tak. CW motor = CW pervane.
10. HOVER TESTİ: 1–2 metre irtifada stabilite kontrolü.
```

---

## 5.3 Saha Güvenlik Protokolleri

```
PRE-FLIGHT (Her Uçuştan Önce):
[ ] Pervane çatlağı görsel kontrolü
[ ] Batarya gerilimi > 4.0V/hücre
[ ] GPS: min 8 uydu, HDOP < 2.0
[ ] RTH yüksekliği ayarlandı mı?
[ ] Çevre: 30 metre boş alan
[ ] Kimsesiz bölge mi?

SAHA KURALLARI:
- Batarya bağlıyken motorların ASLA önünde durma
- Arming öncesi "Clear!" diye seslen
- Kalkışta İHA'nın altına kesinlikle bakma
```

---

## 5.4 Pratik Görevler (Sertifikasyon)

> **Görev 5-A (Lehim):** PDB üzerine 4 motor kablosu + batarya konektörü lehimle. Multimetre ile süreklilik ve kısa devre testi yap.

> **Görev 5-B (Konfigürasyon):** FC'de motor yönlerini doğrula. ESC protokolünü DSHOT300 olarak ayarla.

> **Görev 5-C (Simülasyon):** SITL'de ardupilot ile başarılı bir waypoint görevi tamamla.

---

*← [Modül 4](04_software.md) | [Ana Sayfaya Dön](../README.md)*
