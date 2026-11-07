#include "display.hpp"

LGFX::LGFX() {

    // SPI BUS
    {
        auto cfg = _bus.config();

        cfg.spi_host = SPI2_HOST;
        cfg.spi_mode = 0;
        cfg.freq_write = 40000000;
        cfg.freq_read = 16000000;

        cfg.spi_3wire = true;
        cfg.use_lock = true;
        cfg.dma_channel = SPI_DMA_CH_AUTO;

        cfg.pin_miso = -1;
        cfg.pin_mosi = 6;
        cfg.pin_sclk = 4;
        cfg.pin_dc = 2;

        _bus.config(cfg);
        _panel.setBus(&_bus);
    }

    // PANEL
    {
        auto cfg = _panel.config();

        cfg.pin_cs = 1;
        cfg.pin_rst = 3;

        cfg.panel_width = 135;
        cfg.panel_height = 240;

        cfg.offset_x = 52;
        cfg.offset_y = 40;

        cfg.invert = true;
        cfg.rgb_order = false;
        cfg.readable = false;

        _panel.config(cfg);
    }

    setPanel(&_panel);
}

// Global display instance
LGFX tft;