// Youtube >>> H.M.Ç >>> https://www.youtube.com/@h.m.c3847
// Linkedin >>> https://www.linkedin.com/in/hasan-mesut-%C3%A7etin-975744286/

#include <lvgl.h>
#include <TFT_eSPI.h>  // TFT ekran için

#define TFT_HOR_RES   320
#define TFT_VER_RES   240
#define TFT_ROTATION  LV_DISPLAY_ROTATION_0

// LVGL’nin çizeceği alan için buffer (ekranın 1/10’u kadar genelde yeter)
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// Arduino'nun millis() fonksiyonu LVGL'nin zaman kaynağı olacak
static uint32_t my_tick(void) {
  return millis();
}

void setup() {
  Serial.begin(115200);
  Serial.println("LVGL Başlatiliyor...");

  lv_init(); // LVGL kütüphanesini başlat
  lv_tick_set_cb(my_tick); // Zamanlayıcı olarak millis() kullan

  // --- EKRAN BAĞLANTISI ---
  lv_display_t *disp;
  disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, TFT_ROTATION);

  // --- ARKA PLAN RENGİ AYARLA ---
  lv_obj_t *scr = lv_screen_active(); // Aktif ekran nesnesini al
  lv_obj_set_style_bg_color(scr, lv_color_hex(0x000000), 0);
  /*
    Açıklama:
    lv_color_hex(0x001F3F) → Lacivert bir renk
    0xFFFFFF → Beyaz
    0x000000 → Siyah
    0xFF0000 → Kırmızı
    0x00FF00 → Yeşil
    0x0000FF → Mavi
  */

  // --- YAZI 1  NESNESİ OLUŞTUR ---
  lv_obj_t *label = lv_label_create(scr); // Ekranda yazı nesnesi oluştur
  lv_label_set_text(label, "Selamun Aleykum ESP-32 CYD!"); // Yazı içeriği
  /*
    Burada ekranda gösterilecek yazıyı belirliyoruz.
    Türkçe karakterlerde sorun olursa UTF-8 desteği aktif edilmelidir.
  */



  // --- YAZI STİLİ TANIMLA ---
  static lv_style_t style;    // Stil değişkeni oluştur
  lv_style_init(&style);      // Başlat

  // Yazı fontu (boyutu)
  lv_style_set_text_font(&style, &lv_font_montserrat_20);
  /*
    Font büyüklükleri:
      lv_font_montserrat_12
      lv_font_montserrat_16
      lv_font_montserrat_20
      lv_font_montserrat_28
      lv_font_montserrat_40
    Daha büyük istiyorsan lv_conf.h dosyasında istediğin boyutu aktif et:
    #define LV_FONT_MONTSERRAT_28 1
  */

  // Yazı rengi
  lv_style_set_text_color(&style, lv_color_hex(0xFFD700));
  /*
    0xFFD700 → Altın sarısı
    0xFFFFFF → Beyaz
    0xFF0000 → Kırmızı
    0x00FF00 → Yeşil
    0x0000FF → Mavi
  */

  // Stili label'a uygula
  lv_obj_add_style(label, &style, 0);

  // --- YAZININ KONUMU ---
  lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 0);
  /*
    LV_ALIGN_CENTER → Ortaya yerleştirir.
    LV_ALIGN_TOP_MID → Üste ortalar
    LV_ALIGN_BOTTOM_MID → Alta ortalar
    LV_ALIGN_LEFT_MID → Sola ortalar
    LV_ALIGN_RIGHT_MID → Sağa ortalar
    Son iki değer (0, 0) → X ve Y ekseninde kaydırma (ofset)
    Örnek:
      lv_obj_align(label, LV_ALIGN_TOP_LEFT, 20, 20);
      // Sol üstten 20px sağa ve 20px aşağı
  */

  // Yazı 2 
  lv_obj_t *label2 = lv_label_create(scr); // Ekranda yazı nesnesi oluştur
  lv_label_set_text(label2, "Bu Ekrana Yazi Yazdirma "); // Yazı içeriği
  static lv_style_t style2;    // Stil değişkeni oluştur
  lv_style_init(&style2);      // Başlat
  lv_style_set_text_font(&style2, &lv_font_montserrat_18);// Font Ayarla 
  lv_style_set_text_color(&style2, lv_color_hex(0xFFFFFF)); //Yazı Rengi
  lv_obj_add_style(label2, &style2, 0);// Sitilleri label e uygula
  lv_obj_align(label2, LV_ALIGN_CENTER, 0, 0);// Yazı konumu

  // Yazı 3 
  lv_obj_t *label3 = lv_label_create(scr); // Ekranda yazı nesnesi oluştur
  lv_label_set_text(label3, "Nasil Sin ?"); // Yazı içeriği
  static lv_style_t style3;    // Stil değişkeni oluştur
  lv_style_init(&style3);      // Başlat
  lv_style_set_text_font(&style3, &lv_font_montserrat_16);// Font Ayarla 
  lv_style_set_text_color(&style3, lv_color_hex(0xFF0000)); //Yazı Rengi
  lv_obj_add_style(label3, &style3, 0);// Sitilleri label e uygula
  lv_obj_align(label3, LV_ALIGN_TOP_RIGHT, 0, 220);// Yazı konumu


  Serial.println("Kurulum tamamlandi!");
}

void loop() {
  lv_timer_handler(); // LVGL görevlerini çalıştır
  delay(5);
}
