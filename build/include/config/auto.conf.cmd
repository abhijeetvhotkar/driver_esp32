deps_config := \
	/home/abhi/esp/esp-idf/components/app_trace/Kconfig \
	/home/abhi/esp/esp-idf/components/aws_iot/Kconfig \
	/home/abhi/esp/esp-idf/components/bt/Kconfig \
	/home/abhi/esp/esp-idf/components/esp32/Kconfig \
	/home/abhi/esp/esp-idf/components/esp_adc_cal/Kconfig \
	/home/abhi/esp/esp-idf/components/ethernet/Kconfig \
	/home/abhi/esp/esp-idf/components/fatfs/Kconfig \
	/home/abhi/esp/esp-idf/components/freertos/Kconfig \
	/home/abhi/esp/esp-idf/components/heap/Kconfig \
	/home/abhi/esp/esp-idf/components/libsodium/Kconfig \
	/home/abhi/esp/esp-idf/components/log/Kconfig \
	/home/abhi/esp/esp-idf/components/lwip/Kconfig \
	/home/abhi/esp/esp-idf/components/mbedtls/Kconfig \
	/home/abhi/esp/esp-idf/components/openssl/Kconfig \
	/home/abhi/esp/esp-idf/components/pthread/Kconfig \
	/home/abhi/esp/esp-idf/components/spi_flash/Kconfig \
	/home/abhi/esp/esp-idf/components/spiffs/Kconfig \
	/home/abhi/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/abhi/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/abhi/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/abhi/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/abhi/esp/Project/gpio2/main/Kconfig.projbuild \
	/home/abhi/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/abhi/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
