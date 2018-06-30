__attribute__((section(".symbol_table"))) const char APP_SYM_TABLE[] =
	"000158e8 T ADC_IRQHandler\n"
	"00015e8c T CAN_IRQHandler\n"
	"00015814 T EINT3_IRQHandler\n"
	"00015d8c T I2C2_IRQHandler\n"
	"00015614 T RIT_IRQHandler\n"
	"000149cc T RTC_IRQHandler\n"
	"00010504 T TIMER1_IRQHandler\n"
	"00015b2c T UART0_IRQHandler\n"
	"00015ac4 T UART2_IRQHandler\n"
	"00015a5c T UART3_IRQHandler\n"
	"0001020c T low_level_init()\n"
	"00017034 T high_level_init()\n"
	"000106e0 T sys_clock_configure()\n"
	"00010180 T bss_init(unsigned int, unsigned int)\n"
	"0001016a T data_init(unsigned int, unsigned int, unsigned int)\n"
	"00014370 T LED_Display::setLeftDigit(char)\n"
	"00014388 T LED_Display::setRightDigit(char)\n"
	"000143a0 T LED_Display::init()\n"
	"000143d8 T LED_Display::setNumber(char)\n"
	"000144c4 T Light_Sensor::getRawValue()\n"
	"000144c0 T Light_Sensor::init()\n"
	"0001429c T Acceleration_Sensor::init()\n"
	"00014468 T LED::on(unsigned char)\n"
	"0001448e T LED::off(unsigned char)\n"
	"000144b6 T LED::set(unsigned char, bool)\n"
	"00014412 T LED::init()\n"
	"00014418 T LED::setAll(unsigned char)\n"
	"00015d0c T I2C2::init(unsigned int)\n"
	"00015d78 T I2C2::I2C2()\n"
	"00015d78 T I2C2::I2C2()\n"
	"00015b10 T Uart0::Uart0()\n"
	"00015b10 T Uart0::Uart0()\n"
	"00015aa8 T Uart2::Uart2()\n"
	"00015aa8 T Uart2::Uart2()\n"
	"00015a40 T Uart3::Uart3()\n"
	"00015a40 T Uart3::Uart3()\n"
	"000155dc T CharDev::CharDev()\n"
	"000155dc T CharDev::CharDev()\n"
	"000155fc T CharDev::~CharDev()\n"
	"000155fc T CharDev::~CharDev()\n"
	"00014222 T Storage::read(char const*, void*, unsigned int, unsigned int)\n"
	"000154f0 T UartDev::handleInterrupt()\n"
	"00015464 T UartDev::flush()\n"
	"00015484 T UartDev::getChar(char*, unsigned int)\n"
	"000153e0 T UartDev::putChar(char, unsigned int)\n"
	"000155b0 T UartDev::UartDev(unsigned int*)\n"
	"000155b0 T UartDev::UartDev(unsigned int*)\n"
	"00015156 T I2C_Base::readRegisters(unsigned char, unsigned char*, unsigned long)\n"
	"00015110 T I2C_Base::readRegisters(unsigned char, unsigned char, unsigned char*, unsigned long)\n"
	"0001512a T I2C_Base::writeRegisters(unsigned char, unsigned char*, unsigned long)\n"
	"000153a8 T I2C_Base::handleInterrupt()\n"
	"0001516e T I2C_Base::checkDeviceResponse(unsigned char)\n"
	"000150dc T I2C_Base::writeRegisterThenRead(unsigned char, unsigned char*, unsigned long, unsigned char*, unsigned long)\n"
	"000151e0 T I2C_Base::init(unsigned long, unsigned long)\n"
	"000150e8 T I2C_Base::readReg(unsigned char, unsigned char)\n"
	"00014fd4 T I2C_Base::transfer(unsigned char, unsigned char*, unsigned long, unsigned char*, unsigned long)\n"
	"0001513e T I2C_Base::writeReg(unsigned char, unsigned char, unsigned char)\n"
	"00015184 T I2C_Base::I2C_Base(LPC_I2C_TypeDef*)\n"
	"00015184 T I2C_Base::I2C_Base(LPC_I2C_TypeDef*)\n"
	"0001450a T I2C_Temp::getCelsius()\n"
	"0001453c T I2C_Temp::getFarenheit()\n"
	"000144e8 T I2C_Temp::init()\n"
	"000144d0 T Switches::getSwitchValues()\n"
	"000144ca T Switches::init()\n"
	"000142bc T IR_Sensor::storeIrCode(unsigned long)\n"
	"000142d8 T IR_Sensor::decodeIrCode()\n"
	"0001433c T IR_Sensor::init()\n"
	"0001784c T std::type_info::__is_pointer_p() const\n"
	"0001784c T std::type_info::__is_function_p() const\n"
	"00017850 T std::type_info::operator==(std::type_info const&) const\n"
	"0001784a T std::type_info::~type_info()\n"
	"0001784a T std::type_info::~type_info()\n"
	"00017d08 T std::get_terminate()\n"
	"00017d18 T std::terminate()\n"
	"00018998 T abort\n"
	"000159a4 T adc0_get_reading\n"
	"00015930 T adc0_init\n"
	"000189a6 T atoi\n"
	"00014600 T c_list_create\n"
	"0001464c T c_list_find_elm\n"
	"00014678 T c_list_for_each_elm\n"
	"00014614 T c_list_insert_elm_end\n"
	"00011e30 T clust2sect\n"
	"00014aa2 T delay_ms\n"
	"00014a78 T delay_us\n"
	"00013c40 T disk_initialize\n"
	"00013ce6 T disk_ioctl\n"
	"00013c76 T disk_read\n"
	"00013c66 T disk_status\n"
	"00013cae T disk_write\n"
	"0001bd90 T div\n"
	"00015894 T eint3_enable_port0\n"
	"00012d3c T f_close\n"
	"00012eae T f_getfree\n"
	"00012d60 T f_lseek\n"
	"00012f78 T f_mkfs\n"
	"000127ec T f_mount\n"
	"00012868 T f_open\n"
	"00012996 T f_read\n"
	"00012cb2 T f_sync\n"
	"00012b06 T f_write\n"
	"000134c8 T ff_convert\n"
	"0001346c T ff_cre_syncobj\n"
	"00013480 T ff_del_syncobj\n"
	"000134aa T ff_rel_grant\n"
	"00013484 T ff_req_grant\n"
	"00013504 T ff_wtoupper\n"
	"00018b20 T fflush\n"
	"000141a4 T flash_chip_erase\n"
	"000140dc T flash_get_page_count\n"
	"000140fc T flash_get_page_size\n"
	"00013f04 T flash_initialize\n"
	"00014038 T flash_ioctl\n"
	"000140b4 T flash_read_permanent_id\n"
	"00013f9c T flash_read_sectors\n"
	"00014108 T flash_supports_metadata\n"
	"00014070 T flash_write_permanent_id\n"
	"00013fec T flash_write_sectors\n"
	"00018e54 T free\n"
	"00010000 T g_pfnVectors\n"
	"00011e46 T get_fat\n"
	"000141d0 T get_fattime\n"
	"0001a240 T iprintf\n"
	"00014a94 T is_freertos_running\n"
	"0001a548 T iscanf\n"
	"00010148 T isr_default_handler\n"
	"000105fc T isr_hard_fault_handler\n"
	"00010194 T isr_reset\n"
	"00014828 T logger_init\n"
	"0001092c T lpc_pclk\n"
	"000108f8 T lpc_pconp\n"
	"00010434 T lpc_sys_setup_system_timer\n"
	"00015ca0 T lpc_timer_enable\n"
	"00017594 T main\n"
	"000193d4 T mallinfo\n"
	"00018e44 T malloc\n"
	"00018e88 T memchr\n"
	"00018ea4 T memcmp\n"
	"00018ec2 T memcpy\n"
	"00018ed8 T memmove\n"
	"00018f0c T memset\n"
	"00011414 T mesh_form_pkt\n"
	"00011408 T mesh_get_node_address\n"
	"000116bc T mesh_get_num_routing_entries\n"
	"000119a8 T mesh_get_pnd_pkt_count\n"
	"00011564 T mesh_init\n"
	"00011664 T mesh_send\n"
	"0001150c T mesh_send_formed_pkt\n"
	"000116d8 T mesh_service\n"
	"000113f0 T mesh_set_node_address\n"
	"000190dc T mktime\n"
	"0001a6d4 T nanf\n"
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
	"000135b0 T power_off\n"
	"0001a240 T printf\n"
	"00011f6c T put_fat\n"
	"0001a328 T puts\n"
	"00016030 T pvPortMalloc\n"
	"00016e00 T pvTaskIncrementMutexHeldCount\n"
	"00015ec8 T pxPortInitialiseStack\n"
	"0001a72c T raise\n"
	"0001a388 T rand\n"
	"000135d4 T rcvr_datablock\n"
	"00015630 T rtc_gettime\n"
	"000156e0 T rtc_init\n"
	"00015678 T rtc_settime\n"
	"00015fc0 T rts_not_full_trace_get\n"
	"0001a548 T scanf\n"
	"0001375c T sd_initialize\n"
	"00013a24 T sd_ioctl\n"
	"000138d8 T sd_read\n"
	"000138c8 T sd_status\n"
	"00013738 T sd_update_card_status\n"
	"00013970 T sd_write\n"
	"000136ac T send_cmd\n"
	"0001a578 T setvbuf\n"
	"0001a764 T siprintf\n"
	"0001a7ac T siscanf\n"
	"00015c2c T spi1_lock\n"
	"00015c5c T spi1_unlock\n"
	"0001a764 T sprintf\n"
	"0001a338 T srand\n"
	"0001a7ac T sscanf\n"
	"00015b50 T ssp1_dma_init\n"
	"00015b6c T ssp1_dma_transfer_block\n"
	"0001a88a T strcmp\n"
	"0001a89e T strcpy\n"
	"0001a8ae T strlen\n"
	"0001a8be T strncmp\n"
	"0001a8e2 T strncpy\n"
	"0001b684 T strtol\n"
	"0001e9d8 T strtoul\n"
	"00010200 T sys_get_boot_type\n"
	"00010794 T sys_get_cpu_clock\n"
	"00014b38 T sys_get_mem_info\n"
	"000104b4 T sys_get_mem_info_str\n"
	"00010488 T sys_get_uptime_us\n"
	"00014d44 T sys_set_inchar_func\n"
	"00014d38 T sys_set_outchar_func\n"
	"00014d78 T syscalls_init\n"
	"0001b6b0 T time\n"
	"00014594 T tlm_component_add\n"
	"00014570 T tlm_component_get_by_name\n"
	"00014912 T u0_dbg_printf\n"
	"000148f4 T u0_dbg_put\n"
	"0001089c T uart0_getchar\n"
	"0001083c T uart0_init\n"
	"000108b4 T uart0_putchar\n"
	"000108cc T uart0_puts\n"
	"000160ca T uxListRemove\n"
	"0001668c T uxQueueMessagesWaiting\n"
	"0001669e T uxQueueMessagesWaitingFromISR\n"
	"0001600c T vApplicationMallocFailedHook\n"
	"00015fd4 T vApplicationStackOverflowHook\n"
	"00016068 T vListInitialise\n"
	"0001607e T vListInitialiseItem\n"
	"0001609c T vListInsert\n"
	"00016084 T vListInsertEnd\n"
	"00015f14 T vPortEnterCritical\n"
	"00015f34 T vPortExitCritical\n"
	"0001604e T vPortFree\n"
	"00015ef0 T vPortSVCHandler\n"
	"00016e18 T vRunTimeStatIsrEntry\n"
	"00016e40 T vRunTimeStatIsrExit\n"
	"00016af8 T vTaskDelay\n"
	"00016cd4 T vTaskMissedYield\n"
	"00016be0 T vTaskPlaceOnEventList\n"
	"00016d00 T vTaskPriorityInherit\n"
	"00016c70 T vTaskSetTimeOutState\n"
	"000168f8 T vTaskSuspendAll\n"
	"00016b28 T vTaskSwitchContext\n"
	"0001bb94 T vsniprintf\n"
	"0001bb94 T vsnprintf\n"
	"00013580 T wait_ready\n"
	"00010f88 T wireless_init\n"
	"00010fd4 T wireless_service\n"
	"00015f50 T xPortPendSVHandler\n"
	"00015f94 T xPortSysTickHandler\n"
	"000163e4 T xQueueCreateMutex\n"
	"000162ac T xQueueGenericCreate\n"
	"000164f0 T xQueueGenericReceive\n"
	"00016240 T xQueueGenericReset\n"
	"000162e0 T xQueueGenericSend\n"
	"00016408 T xQueueGenericSendFromISR\n"
	"00016488 T xQueueGiveFromISR\n"
	"00016624 T xQueueReceiveFromISR\n"
	"00016c88 T xTaskCheckForTimeOut\n"
	"00016754 T xTaskCreate\n"
	"00016ce0 T xTaskGetSchedulerState\n"
	"00016908 T xTaskGetTickCountFromISR\n"
	"00016914 T xTaskIncrementTick\n"
	"00016d90 T xTaskPriorityDisinherit\n"
	"00016c00 T xTaskRemoveFromEventList\n"
	"00016a20 T xTaskResumeAll\n"
	"00013660 T xmit_datablock\n"
;
