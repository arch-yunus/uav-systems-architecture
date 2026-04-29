"""
🦅 SUNGUR Tactical Decision Engine (TDE)
Version: 1.0.0-OMEGA
Architecture: Decentralized Siber-Asabiyet
Developed with ⚔️ by arch-yunus

Bu modül, İHA'nın görev esnasında karşılaştığı karmaşık durumlarda (jamming, düşük batarya, hedef kaybı)
en uygun otonom kararı vermesini sağlayan 'Cognitive Decision Logic' katmanıdır.
"""

import math
import logging
from enum import Enum
from dataclasses import dataclass
from typing import List, Optional

# --- Taktik Durumlar ---
class TacticalState(Enum):
    NOMINAL = "NOMINAL"
    INTERFERENCE_DETECTED = "EH_GIRISIMI"
    CRITICAL_BATTERY = "KRITIK_BATARYA"
    TARGET_LOCKED = "HEDEF_KILIT"
    FAILSAFE_RTH = "GÜVENLİ_DÖNÜŞ"

@dataclass
class TelemetryFrame:
    altitude: float
    battery_percentage: float
    jamming_intensity: float  # 0.0 to 1.0
    is_target_in_sight: bool

class TacticalEngine:
    def __init__(self):
        self.logger = logging.getLogger("SUNGUR_TDE")
        self._current_state = TacticalState.NOMINAL
        self._is_failsafe_active = False

    def process_tactical_cycle(self, frame: TelemetryFrame) -> TacticalState:
        """
        Her 100ms'de bir çağrılan ana karar döngüsü.
        Siber-Asabiyet prensiplerine göre önceliklendirme yapar.
        """
        self.logger.info(f"Döngü İşleniyor: Alt={frame.altitude}m, Batt={frame.battery_percentage}%")

        # 1. Kritik Güvenlik Kontrolü (Failsafe First)
        if frame.battery_percentage < 15.0:
            return self._initiate_failsafe(TacticalState.CRITICAL_BATTERY)

        # 2. EH (Elektronik Harp) Durumu Değerlendirmesi
        if frame.jamming_intensity > 0.7:
            return self._handle_interference()

        # 3. Görev Mantığı
        if frame.is_target_in_sight:
            self._current_state = TacticalState.TARGET_LOCKED
        else:
            self._current_state = TacticalState.NOMINAL

        return self._current_state

    def _initiate_failsafe(self, cause: TacticalState) -> TacticalState:
        self.logger.warning(f"Kritik Durum: {cause.value} | Failsafe Moduna Geçiliyor!")
        self._is_failsafe_active = True
        return TacticalState.FAILSAFE_RTH

    def _handle_interference(self) -> TacticalState:
        """
        GNSS-Denied navigasyon ve frekans atlamalı (FHSS) iletişime geçiş kararını tetikler.
        """
        self.logger.critical("Yüksek Yoğunluklu EH Tespit Edildi! OMEGA-Shield Aktif.")
        return TacticalState.INTERFERENCE_DETECTED

if __name__ == "__main__":
    # Örnek Operasyonel Senaryo
    engine = TacticalEngine()
    
    # Senaryo: EH Altında Görev
    test_frame = TelemetryFrame(
        altitude=120.5,
        battery_percentage=45.0,
        jamming_intensity=0.85,
        is_target_in_sight=True
    )
    
    result = engine.process_tactical_cycle(test_frame)
    print(f"\n[SUNGUR_DECISION] >>> {result.name} ({result.value})\n")
