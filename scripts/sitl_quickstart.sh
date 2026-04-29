#!/bin/bash

# ============================================================
#  UAV Engineering Bootcamp — SITL Hızlı Başlatma Scripti
#  Modül 4: Yazılım ve Konfigürasyon / Soft 101
# ============================================================
#
# Bu script, ArduPilot SITL ortamını tek komutla hazırlar.
# Gerçek drone'a gitmeden önce tüm algoritmalarını burada test et.
#
# KULLANIM:
#   chmod +x scripts/sitl_quickstart.sh
#   ./scripts/sitl_quickstart.sh
#
# ÖN KOŞULLAR:
#   Ubuntu 22.04 LTS
#   ArduPilot kaynak kodu klonlanmış
#   Python 3.10+
# ============================================================

set -e  # Herhangi bir hata olursa scripti durdur

# ─────────────────────────────────────────────────────────────
# RENK KODLARI (terminal çıktısı için)
# ─────────────────────────────────────────────────────────────
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'  # No Color

log_info()    { echo -e "${BLUE}[INFO]${NC}  $1"; }
log_success() { echo -e "${GREEN}[OK]${NC}    $1"; }
log_warn()    { echo -e "${YELLOW}[UYARI]${NC} $1"; }
log_error()   { echo -e "${RED}[HATA]${NC}  $1"; }

# ─────────────────────────────────────────────────────────────
# BAŞLIK
# ─────────────────────────────────────────────────────────────
echo ""
echo "=============================================="
echo "   UAV Engineering Bootcamp — SITL Launcher  "
echo "   Modül 4: Yazılım ve Konfigürasyon          "
echo "=============================================="
echo ""

# ─────────────────────────────────────────────────────────────
# BAĞIMLILIK KONTROLÜ
# ─────────────────────────────────────────────────────────────
log_info "Bağımlılıklar kontrol ediliyor..."

check_dependency() {
    if ! command -v "$1" &> /dev/null; then
        log_error "'$1' bulunamadı. Lütfen önce kurulumu yapın."
        log_error "Detay: scripts/bootstrap.sh --install-all"
        exit 1
    fi
    log_success "'$1' bulundu."
}

check_dependency python3
check_dependency pip3
check_dependency mavproxy.py 2>/dev/null || log_warn "mavproxy kurulu değil → pip3 install MAVProxy"

# ─────────────────────────────────────────────────────────────
# ARDUPILOT KLASÖRÜ KONTROLÜ
# ─────────────────────────────────────────────────────────────
ARDUPILOT_DIR="${HOME}/ardupilot"

if [ ! -d "$ARDUPILOT_DIR" ]; then
    log_warn "ArduPilot dizini bulunamadı: $ARDUPILOT_DIR"
    log_info "Klonlanıyor... (Bu bir kere yapılır)"
    git clone --depth=1 https://github.com/ArduPilot/ardupilot.git "$ARDUPILOT_DIR"
    cd "$ARDUPILOT_DIR"
    git submodule update --init --recursive
    ./Tools/environment_install/install-prereqs-ubuntu.sh -y
    . ~/.profile
    log_success "ArduPilot klonlama tamamlandı."
fi

# ─────────────────────────────────────────────────────────────
# SIMÜLASYON PARAMETRELERİ
# ─────────────────────────────────────────────────────────────
VEHICLE="ArduCopter"       # Araç tipi
FRAME="++"                 # + veya X frame
LOCATION="ATATÜRK"        # Başlangıç konumu (özel isim)

# Ankara koordinatları (yaklaşık merkez)
LAT="39.9334"
LON="32.8597"
ALT="900"   # Deniz seviyesinden yükseklik (m) - Ankara ~900m

log_info "SITL başlatılıyor: $VEHICLE | Frame: $FRAME"
log_info "Konum: Ankara ($LAT, $LON) | İrtifa: ${ALT}m MSL"
echo ""

# ─────────────────────────────────────────────────────────────
# SITL BAŞLATMA
# ─────────────────────────────────────────────────────────────
cd "$ARDUPILOT_DIR"

log_success "Simülatör başlatılıyor... GCS için Mission Planner'ı aç ve UDP:14550'ye bağlan."
echo ""
echo "Temel MAVProxy komutları:"
echo "  arm throttle      — Motorları arm et"
echo "  takeoff 10        — 10m irtifaya çık"
echo "  mode RTL          — Eve dön"
echo "  mode GUIDED       — Manuel GPS hedef modu"
echo "  wp list           — Waypoint listesi"
echo ""

sim_vehicle.py \
    -v "$VEHICLE" \
    --frame="$FRAME" \
    --console \
    --map \
    --home="$LAT,$LON,$ALT,0" \
    --out=udp:127.0.0.1:14550 \
    --out=udp:127.0.0.1:14551

# ─────────────────────────────────────────────────────────────
# ÇIKIŞ
# ─────────────────────────────────────────────────────────────
log_info "SITL oturumu sonlandı."
