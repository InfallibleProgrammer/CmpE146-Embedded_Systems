__attribute__((section(".symbol_table"))) const char APP_SYM_TABLE[] =
	"000159c0 T ADC_IRQHandler\n"
	"00015f5c T CAN_IRQHandler\n"
	"000158ec T EINT3_IRQHandler\n"
	"00015e60 T I2C2_IRQHandler\n"
	"000156ec T RIT_IRQHandler\n"
	"00014aec T RTC_IRQHandler\n"
	"00010504 T TIMER1_IRQHandler\n"
	"00015c04 T UART0_IRQHandler\n"
	"00015b9c T UART2_IRQHandler\n"
	"00015b34 T UART3_IRQHandler\n"
	"0001020c T low_level_init()\n"
	"00017104 T high_level_init()\n"
	"000106e0 T sys_clock_configure()\n"
	"00010180 T bss_init(unsigned int, unsigned int)\n"
	"00017678 T writeSCI(unsigned char, unsigned short)\n"
	"0001016a T data_init(unsigned int, unsigned int, unsigned int)\n"
	"000176d8 T setVolume(unsigned char, unsigned char)\n"
	"000144e8 T LED_Display::setLeftDigit(char)\n"
	"00014500 T LED_Display::setRightDigit(char)\n"
	"00014518 T LED_Display::init()\n"
	"00014550 T LED_Display::setNumber(char)\n"
	"000145e4 T Light_Sensor::getRawValue()\n"
	"000145e0 T Light_Sensor::init()\n"
	"00014414 T Acceleration_Sensor::init()\n"
	"0001458a T LED::init()\n"
	"00014590 T LED::setAll(unsigned char)\n"
	"000142e4 T GPIO::setAsInput()\n"
	"000142f6 T GPIO::setAsOutput()\n"
	"00014334 T GPIO::enablePullUp()\n"
	"00014354 T GPIO::enableOpenDrainMode(bool)\n"
	"00014326 T GPIO::setLow()\n"
	"0001431a T GPIO::setHigh()\n"
	"00014294 T GPIO::GPIO(LPC1758_GPIO_Type)\n"
	"00014294 T GPIO::GPIO(LPC1758_GPIO_Type)\n"
	"00014380 T GPIO::~GPIO()\n"
	"00014380 T GPIO::~GPIO()\n"
	"00015de4 T I2C2::init(unsigned int)\n"
	"00015e4c T I2C2::I2C2()\n"
	"00015e4c T I2C2::I2C2()\n"
	"00015be8 T Uart0::Uart0()\n"
	"00015be8 T Uart0::Uart0()\n"
	"00015b80 T Uart2::Uart2()\n"
	"00015b80 T Uart2::Uart2()\n"
	"00015b18 T Uart3::Uart3()\n"
	"00015b18 T Uart3::Uart3()\n"
	"000156b4 T CharDev::CharDev()\n"
	"000156b4 T CharDev::CharDev()\n"
	"000156d4 T CharDev::~CharDev()\n"
	"000156d4 T CharDev::~CharDev()\n"
	"0001439a T Storage::read(char const*, void*, unsigned int, unsigned int)\n"
	"000155c8 T UartDev::handleInterrupt()\n"
	"0001553c T UartDev::flush()\n"
	"0001555c T UartDev::getChar(char*, unsigned int)\n"
	"000154b8 T UartDev::putChar(char, unsigned int)\n"
	"00015688 T UartDev::UartDev(unsigned int*)\n"
	"00015688 T UartDev::UartDev(unsigned int*)\n"
	"000151d0 T I2C_Base::readRegisters(unsigned char, unsigned char, unsigned char*, unsigned long)\n"
	"000151f2 T I2C_Base::writeRegisters(unsigned char, unsigned char, unsigned char*, unsigned long)\n"
	"00015484 T I2C_Base::handleInterrupt()\n"
	"0001530c T I2C_Base::i2cStateMachine()\n"
	"00015210 T I2C_Base::checkDeviceResponse(unsigned char)\n"
	"00015278 T I2C_Base::init(unsigned long, unsigned long)\n"
	"000151d8 T I2C_Base::readReg(unsigned char, unsigned char)\n"
	"000150f8 T I2C_Base::transfer(unsigned char, unsigned char, unsigned char*, unsigned long)\n"
	"000151fa T I2C_Base::writeReg(unsigned char, unsigned char, unsigned char)\n"
	"00015228 T I2C_Base::I2C_Base(LPC_I2C_TypeDef*)\n"
	"00015228 T I2C_Base::I2C_Base(LPC_I2C_TypeDef*)\n"
	"0001462a T I2C_Temp::getCelsius()\n"
	"0001465c T I2C_Temp::getFarenheit()\n"
	"00014608 T I2C_Temp::init()\n"
	"000145f0 T Switches::getSwitchValues()\n"
	"000145ea T Switches::init()\n"
	"00014434 T IR_Sensor::storeIrCode(unsigned long)\n"
	"00014450 T IR_Sensor::decodeIrCode()\n"
	"000144b4 T IR_Sensor::init()\n"
	"00014306 T GPIO::read() const\n"
	"00017b34 T std::type_info::__is_pointer_p() const\n"
	"00017b34 T std::type_info::__is_function_p() const\n"
	"00017b38 T std::type_info::operator==(std::type_info const&) const\n"
	"00017b32 T std::type_info::~type_info()\n"
	"00017b32 T std::type_info::~type_info()\n"
	"00017ff0 T std::get_terminate()\n"
	"00018000 T std::terminate()\n"
	"00018c80 T abort\n"
	"00015a7c T adc0_get_reading\n"
	"00015a08 T adc0_init\n"
	"00018c8e T atoi\n"
	"00014720 T c_list_create\n"
	"0001476c T c_list_find_elm\n"
	"00014798 T c_list_for_each_elm\n"
	"00014734 T c_list_insert_elm_end\n"
	"00011e3c T clust2sect\n"
	"00014bc2 T delay_ms\n"
	"00014b98 T delay_us\n"
	"00013cb0 T disk_initialize\n"
	"00013d56 T disk_ioctl\n"
	"00013ce6 T disk_read\n"
	"00013cd6 T disk_status\n"
	"00013d1e T disk_write\n"
	"0001c078 T div\n"
	"0001596c T eint3_enable_port0\n"
	"00012dac T f_close\n"
	"00012f1e T f_getfree\n"
	"00012dd0 T f_lseek\n"
	"00012fe8 T f_mkfs\n"
	"0001285c T f_mount\n"
	"000128d8 T f_open\n"
	"00012a06 T f_read\n"
	"00012d22 T f_sync\n"
	"00012b76 T f_write\n"
	"00013538 T ff_convert\n"
	"000134dc T ff_cre_syncobj\n"
	"000134f0 T ff_del_syncobj\n"
	"0001351a T ff_rel_grant\n"
	"000134f4 T ff_req_grant\n"
	"00013574 T ff_wtoupper\n"
	"00018e08 T fflush\n"
	"00014214 T flash_chip_erase\n"
	"0001414c T flash_get_page_count\n"
	"0001416c T flash_get_page_size\n"
	"00013f74 T flash_initialize\n"
	"000140a8 T flash_ioctl\n"
	"00014124 T flash_read_permanent_id\n"
	"0001400c T flash_read_sectors\n"
	"00014178 T flash_supports_metadata\n"
	"000140e0 T flash_write_permanent_id\n"
	"0001405c T flash_write_sectors\n"
	"0001913c T free\n"
	"00010000 T g_pfnVectors\n"
	"00011e52 T get_fat\n"
	"00014240 T get_fattime\n"
	"0001a528 T iprintf\n"
	"00014bb4 T is_freertos_running\n"
	"0001a830 T iscanf\n"
	"00010148 T isr_default_handler\n"
	"000105fc T isr_hard_fault_handler\n"
	"00010194 T isr_reset\n"
	"00014948 T logger_init\n"
	"0001092c T lpc_pclk\n"
	"000108f8 T lpc_pconp\n"
	"00010434 T lpc_sys_setup_system_timer\n"
	"00015d78 T lpc_timer_enable\n"
	"00017704 T main\n"
	"000196bc T mallinfo\n"
	"0001912c T malloc\n"
	"00019170 T memchr\n"
	"0001918c T memcmp\n"
	"000191aa T memcpy\n"
	"000191c0 T memmove\n"
	"000191f4 T memset\n"
	"00011414 T mesh_form_pkt\n"
	"00011408 T mesh_get_node_address\n"
	"000116bc T mesh_get_num_routing_entries\n"
	"000119a8 T mesh_get_pnd_pkt_count\n"
	"00011564 T mesh_init\n"
	"00011664 T mesh_send\n"
	"0001150c T mesh_send_formed_pkt\n"
	"000116d8 T mesh_service\n"
	"000113f0 T mesh_set_node_address\n"
	"000193c4 T mktime\n"
	"0001a9bc T nanf\n"
	"00010aa8 T nordic_clear_all_intr_flags\n"
	"00010b78 T nordic_clear_packet_available_flag\n"
	"00010b08 T nordic_clear_packet_sent_flag\n"
	"00010b94 T nordic_flush_rx_fifo\n"
	"00010b10 T nordic_flush_tx_fifo\n"
	"00010d28 T nordic_init\n"
	"00010b68 T nordic_is_packet_available\n"
	"00010a9a T nordic_is_tx_fifo_empty\n"
	"00010b1c T nordic_mode1_send_single_packet\n"
	"00010c2e T nordic_power_down\n"
	"00010c16 T nordic_power_up\n"
	"00010ab0 T nordic_queue_tx_fifo\n"
	"00010b80 T nordic_read_rx_fifo\n"
	"00010ad4 T nordic_rx_to_Stanby1\n"
	"00010cf8 T nordic_set_addr_width\n"
	"00010c68 T nordic_set_air_data_rate\n"
	"00010cb8 T nordic_set_auto_transmit_options\n"
	"00010c44 T nordic_set_channel\n"
	"00010bde T nordic_set_crc\n"
	"00010ba0 T nordic_set_intr_signals\n"
	"00010ce4 T nordic_set_payload_for_pipe\n"
	"00010c94 T nordic_set_power_level\n"
	"00010d1a T nordic_set_rx_pipe0_addr\n"
	"00010d0e T nordic_set_tx_address\n"
	"00010ae4 T nordic_standby1_to_rx\n"
	"00010abc T nordic_standby1_to_tx_mode1\n"
	"00013620 T power_off\n"
	"0001a528 T printf\n"
	"00011f78 T put_fat\n"
	"0001a610 T puts\n"
	"00016100 T pvPortMalloc\n"
	"00016ed0 T pvTaskIncrementMutexHeldCount\n"
	"00015f98 T pxPortInitialiseStack\n"
	"0001aa14 T raise\n"
	"0001a670 T rand\n"
	"00013644 T rcvr_datablock\n"
	"00015708 T rtc_gettime\n"
	"000157b8 T rtc_init\n"
	"00015750 T rtc_settime\n"
	"00016090 T rts_not_full_trace_get\n"
	"0001a830 T scanf\n"
	"000137cc T sd_initialize\n"
	"00013a94 T sd_ioctl\n"
	"00013948 T sd_read\n"
	"00013938 T sd_status\n"
	"000137a8 T sd_update_card_status\n"
	"000139e0 T sd_write\n"
	"0001371c T send_cmd\n"
	"0001a860 T setvbuf\n"
	"0001aa4c T siprintf\n"
	"0001aa94 T siscanf\n"
	"00015d04 T spi1_lock\n"
	"00015d34 T spi1_unlock\n"
	"0001aa4c T sprintf\n"
	"0001a620 T srand\n"
	"0001aa94 T sscanf\n"
	"00015c28 T ssp1_dma_init\n"
	"00015c44 T ssp1_dma_transfer_block\n"
	"0001ab72 T strcmp\n"
	"0001ab86 T strcpy\n"
	"0001ab96 T strlen\n"
	"0001aba6 T strncmp\n"
	"0001abca T strncpy\n"
	"0001b96c T strtol\n"
	"0001ecc0 T strtoul\n"
	"00010200 T sys_get_boot_type\n"
	"00010794 T sys_get_cpu_clock\n"
	"00014c58 T sys_get_mem_info\n"
	"000104b4 T sys_get_mem_info_str\n"
	"00010488 T sys_get_uptime_us\n"
	"00014e68 T sys_set_inchar_func\n"
	"00014e5c T sys_set_outchar_func\n"
	"00014e9c T syscalls_init\n"
	"0001b998 T time\n"
	"000146b4 T tlm_component_add\n"
	"00014690 T tlm_component_get_by_name\n"
	"00014a32 T u0_dbg_printf\n"
	"00014a14 T u0_dbg_put\n"
	"0001089c T uart0_getchar\n"
	"0001083c T uart0_init\n"
	"000108b4 T uart0_putchar\n"
	"000108cc T uart0_puts\n"
	"0001619a T uxListRemove\n"
	"0001675c T uxQueueMessagesWaiting\n"
	"0001676e T uxQueueMessagesWaitingFromISR\n"
	"000160dc T vApplicationMallocFailedHook\n"
	"000160a4 T vApplicationStackOverflowHook\n"
	"00016138 T vListInitialise\n"
	"0001614e T vListInitialiseItem\n"
	"0001616c T vListInsert\n"
	"00016154 T vListInsertEnd\n"
	"00015fe4 T vPortEnterCritical\n"
	"00016004 T vPortExitCritical\n"
	"0001611e T vPortFree\n"
	"00015fc0 T vPortSVCHandler\n"
	"00016ee8 T vRunTimeStatIsrEntry\n"
	"00016f10 T vRunTimeStatIsrExit\n"
	"00016bc8 T vTaskDelay\n"
	"00016da4 T vTaskMissedYield\n"
	"00016cb0 T vTaskPlaceOnEventList\n"
	"00016dd0 T vTaskPriorityInherit\n"
	"00016d40 T vTaskSetTimeOutState\n"
	"000169c8 T vTaskSuspendAll\n"
	"00016bf8 T vTaskSwitchContext\n"
	"0001be7c T vsniprintf\n"
	"0001be7c T vsnprintf\n"
	"000135f0 T wait_ready\n"
	"00010f88 T wireless_init\n"
	"00010fd4 T wireless_service\n"
	"00016020 T xPortPendSVHandler\n"
	"00016064 T xPortSysTickHandler\n"
	"000164b4 T xQueueCreateMutex\n"
	"0001637c T xQueueGenericCreate\n"
	"000165c0 T xQueueGenericReceive\n"
	"00016310 T xQueueGenericReset\n"
	"000163b0 T xQueueGenericSend\n"
	"000164d8 T xQueueGenericSendFromISR\n"
	"00016558 T xQueueGiveFromISR\n"
	"000166f4 T xQueueReceiveFromISR\n"
	"00016d58 T xTaskCheckForTimeOut\n"
	"00016824 T xTaskCreate\n"
	"00016db0 T xTaskGetSchedulerState\n"
	"000169d8 T xTaskGetTickCountFromISR\n"
	"000169e4 T xTaskIncrementTick\n"
	"00016e60 T xTaskPriorityDisinherit\n"
	"00016cd0 T xTaskRemoveFromEventList\n"
	"00016af0 T xTaskResumeAll\n"
	"000136d0 T xmit_datablock\n"
;
