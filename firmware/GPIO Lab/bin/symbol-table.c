__attribute__((section(".symbol_table"))) const char APP_SYM_TABLE[] =
	"00015890 T ADC_IRQHandler\n"
	"00015e34 T CAN_IRQHandler\n"
	"000157bc T EINT3_IRQHandler\n"
	"00015d34 T I2C2_IRQHandler\n"
	"000155bc T RIT_IRQHandler\n"
	"00014974 T RTC_IRQHandler\n"
	"00010504 T TIMER1_IRQHandler\n"
	"00015ad4 T UART0_IRQHandler\n"
	"00015a6c T UART2_IRQHandler\n"
	"00015a04 T UART3_IRQHandler\n"
	"0001020c T low_level_init()\n"
	"00016fe4 T high_level_init()\n"
	"000106e0 T sys_clock_configure()\n"
	"00010180 T bss_init(unsigned int, unsigned int)\n"
	"0001016a T data_init(unsigned int, unsigned int, unsigned int)\n"
	"00014370 T LED_Display::setLeftDigit(char)\n"
	"00014388 T LED_Display::setRightDigit(char)\n"
	"000143a0 T LED_Display::init()\n"
	"000143d8 T LED_Display::setNumber(char)\n"
	"0001446c T Light_Sensor::getRawValue()\n"
	"00014468 T Light_Sensor::init()\n"
	"0001429c T Acceleration_Sensor::init()\n"
	"00014412 T LED::init()\n"
	"00014418 T LED::setAll(unsigned char)\n"
	"00015cb4 T I2C2::init(unsigned int)\n"
	"00015d20 T I2C2::I2C2()\n"
	"00015d20 T I2C2::I2C2()\n"
	"00015ab8 T Uart0::Uart0()\n"
	"00015ab8 T Uart0::Uart0()\n"
	"00015a50 T Uart2::Uart2()\n"
	"00015a50 T Uart2::Uart2()\n"
	"000159e8 T Uart3::Uart3()\n"
	"000159e8 T Uart3::Uart3()\n"
	"00015584 T CharDev::CharDev()\n"
	"00015584 T CharDev::CharDev()\n"
	"000155a4 T CharDev::~CharDev()\n"
	"000155a4 T CharDev::~CharDev()\n"
	"00014222 T Storage::read(char const*, void*, unsigned int, unsigned int)\n"
	"00015498 T UartDev::handleInterrupt()\n"
	"0001540c T UartDev::flush()\n"
	"0001542c T UartDev::getChar(char*, unsigned int)\n"
	"00015388 T UartDev::putChar(char, unsigned int)\n"
	"00015558 T UartDev::UartDev(unsigned int*)\n"
	"00015558 T UartDev::UartDev(unsigned int*)\n"
	"000150fe T I2C_Base::readRegisters(unsigned char, unsigned char*, unsigned long)\n"
	"000150b8 T I2C_Base::readRegisters(unsigned char, unsigned char, unsigned char*, unsigned long)\n"
	"000150d2 T I2C_Base::writeRegisters(unsigned char, unsigned char*, unsigned long)\n"
	"00015350 T I2C_Base::handleInterrupt()\n"
	"00015116 T I2C_Base::checkDeviceResponse(unsigned char)\n"
	"00015084 T I2C_Base::writeRegisterThenRead(unsigned char, unsigned char*, unsigned long, unsigned char*, unsigned long)\n"
	"00015188 T I2C_Base::init(unsigned long, unsigned long)\n"
	"00015090 T I2C_Base::readReg(unsigned char, unsigned char)\n"
	"00014f7c T I2C_Base::transfer(unsigned char, unsigned char*, unsigned long, unsigned char*, unsigned long)\n"
	"000150e6 T I2C_Base::writeReg(unsigned char, unsigned char, unsigned char)\n"
	"0001512c T I2C_Base::I2C_Base(LPC_I2C_TypeDef*)\n"
	"0001512c T I2C_Base::I2C_Base(LPC_I2C_TypeDef*)\n"
	"000144b2 T I2C_Temp::getCelsius()\n"
	"000144e4 T I2C_Temp::getFarenheit()\n"
	"00014490 T I2C_Temp::init()\n"
	"00014478 T Switches::getSwitchValues()\n"
	"00014472 T Switches::init()\n"
	"000142bc T IR_Sensor::storeIrCode(unsigned long)\n"
	"000142d8 T IR_Sensor::decodeIrCode()\n"
	"0001433c T IR_Sensor::init()\n"
	"00017790 T std::type_info::__is_pointer_p() const\n"
	"00017790 T std::type_info::__is_function_p() const\n"
	"00017794 T std::type_info::operator==(std::type_info const&) const\n"
	"0001778e T std::type_info::~type_info()\n"
	"0001778e T std::type_info::~type_info()\n"
	"00017c4c T std::get_terminate()\n"
	"00017c5c T std::terminate()\n"
	"000188dc T abort\n"
	"0001594c T adc0_get_reading\n"
	"000158d8 T adc0_init\n"
	"000188ea T atoi\n"
	"000145a8 T c_list_create\n"
	"000145f4 T c_list_find_elm\n"
	"00014620 T c_list_for_each_elm\n"
	"000145bc T c_list_insert_elm_end\n"
	"00011e30 T clust2sect\n"
	"00014a4a T delay_ms\n"
	"00014a20 T delay_us\n"
	"00013c40 T disk_initialize\n"
	"00013ce6 T disk_ioctl\n"
	"00013c76 T disk_read\n"
	"00013c66 T disk_status\n"
	"00013cae T disk_write\n"
	"0001bcd8 T div\n"
	"0001583c T eint3_enable_port0\n"
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
	"00018a64 T fflush\n"
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
	"00018d98 T free\n"
	"00010000 T g_pfnVectors\n"
	"00011e46 T get_fat\n"
	"000141d0 T get_fattime\n"
	"0001a184 T iprintf\n"
	"00014a3c T is_freertos_running\n"
	"0001a48c T iscanf\n"
	"00010148 T isr_default_handler\n"
	"000105fc T isr_hard_fault_handler\n"
	"00010194 T isr_reset\n"
	"000147d0 T logger_init\n"
	"0001092c T lpc_pclk\n"
	"000108f8 T lpc_pconp\n"
	"00010434 T lpc_sys_setup_system_timer\n"
	"00015c48 T lpc_timer_enable\n"
	"00017544 T main\n"
	"00019318 T mallinfo\n"
	"00018d88 T malloc\n"
	"00018dcc T memchr\n"
	"00018de8 T memcmp\n"
	"00018e06 T memcpy\n"
	"00018e1c T memmove\n"
	"00018e50 T memset\n"
	"00011414 T mesh_form_pkt\n"
	"00011408 T mesh_get_node_address\n"
	"000116bc T mesh_get_num_routing_entries\n"
	"000119a8 T mesh_get_pnd_pkt_count\n"
	"00011564 T mesh_init\n"
	"00011664 T mesh_send\n"
	"0001150c T mesh_send_formed_pkt\n"
	"000116d8 T mesh_service\n"
	"000113f0 T mesh_set_node_address\n"
	"00019020 T mktime\n"
	"0001a618 T nanf\n"
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
	"0001a184 T printf\n"
	"00011f6c T put_fat\n"
	"0001a26c T puts\n"
	"00015fe0 T pvPortMalloc\n"
	"00016db0 T pvTaskIncrementMutexHeldCount\n"
	"00015e70 T pxPortInitialiseStack\n"
	"0001a670 T raise\n"
	"0001a2cc T rand\n"
	"000135d4 T rcvr_datablock\n"
	"000155d8 T rtc_gettime\n"
	"00015688 T rtc_init\n"
	"00015620 T rtc_settime\n"
	"00015f70 T rts_not_full_trace_get\n"
	"0001a48c T scanf\n"
	"0001375c T sd_initialize\n"
	"00013a24 T sd_ioctl\n"
	"000138d8 T sd_read\n"
	"000138c8 T sd_status\n"
	"00013738 T sd_update_card_status\n"
	"00013970 T sd_write\n"
	"000136ac T send_cmd\n"
	"0001a4bc T setvbuf\n"
	"0001a6a8 T siprintf\n"
	"0001a6f0 T siscanf\n"
	"00015bd4 T spi1_lock\n"
	"00015c04 T spi1_unlock\n"
	"0001a6a8 T sprintf\n"
	"0001a27c T srand\n"
	"0001a6f0 T sscanf\n"
	"00015af8 T ssp1_dma_init\n"
	"00015b14 T ssp1_dma_transfer_block\n"
	"0001a7ce T strcmp\n"
	"0001a7e2 T strcpy\n"
	"0001a7f2 T strlen\n"
	"0001a802 T strncmp\n"
	"0001a826 T strncpy\n"
	"0001b5cc T strtol\n"
	"0001e920 T strtoul\n"
	"00010200 T sys_get_boot_type\n"
	"00010794 T sys_get_cpu_clock\n"
	"00014ae0 T sys_get_mem_info\n"
	"000104b4 T sys_get_mem_info_str\n"
	"00010488 T sys_get_uptime_us\n"
	"00014cec T sys_set_inchar_func\n"
	"00014ce0 T sys_set_outchar_func\n"
	"00014d20 T syscalls_init\n"
	"0001b5f8 T time\n"
	"0001453c T tlm_component_add\n"
	"00014518 T tlm_component_get_by_name\n"
	"000148ba T u0_dbg_printf\n"
	"0001489c T u0_dbg_put\n"
	"0001089c T uart0_getchar\n"
	"0001083c T uart0_init\n"
	"000108b4 T uart0_putchar\n"
	"000108cc T uart0_puts\n"
	"0001607a T uxListRemove\n"
	"0001663c T uxQueueMessagesWaiting\n"
	"0001664e T uxQueueMessagesWaitingFromISR\n"
	"00015fbc T vApplicationMallocFailedHook\n"
	"00015f84 T vApplicationStackOverflowHook\n"
	"00016018 T vListInitialise\n"
	"0001602e T vListInitialiseItem\n"
	"0001604c T vListInsert\n"
	"00016034 T vListInsertEnd\n"
	"00015ec4 T vPortEnterCritical\n"
	"00015ee4 T vPortExitCritical\n"
	"00015ffe T vPortFree\n"
	"00015ea0 T vPortSVCHandler\n"
	"00016dc8 T vRunTimeStatIsrEntry\n"
	"00016df0 T vRunTimeStatIsrExit\n"
	"00016aa8 T vTaskDelay\n"
	"00016c84 T vTaskMissedYield\n"
	"00016b90 T vTaskPlaceOnEventList\n"
	"00016cb0 T vTaskPriorityInherit\n"
	"00016c20 T vTaskSetTimeOutState\n"
	"000168a8 T vTaskSuspendAll\n"
	"00016ad8 T vTaskSwitchContext\n"
	"0001badc T vsniprintf\n"
	"0001badc T vsnprintf\n"
	"00013580 T wait_ready\n"
	"00010f88 T wireless_init\n"
	"00010fd4 T wireless_service\n"
	"00015f00 T xPortPendSVHandler\n"
	"00015f44 T xPortSysTickHandler\n"
	"00016394 T xQueueCreateMutex\n"
	"0001625c T xQueueGenericCreate\n"
	"000164a0 T xQueueGenericReceive\n"
	"000161f0 T xQueueGenericReset\n"
	"00016290 T xQueueGenericSend\n"
	"000163b8 T xQueueGenericSendFromISR\n"
	"00016438 T xQueueGiveFromISR\n"
	"000165d4 T xQueueReceiveFromISR\n"
	"00016c38 T xTaskCheckForTimeOut\n"
	"00016704 T xTaskCreate\n"
	"00016c90 T xTaskGetSchedulerState\n"
	"000168b8 T xTaskGetTickCountFromISR\n"
	"000168c4 T xTaskIncrementTick\n"
	"00016d40 T xTaskPriorityDisinherit\n"
	"00016bb0 T xTaskRemoveFromEventList\n"
	"000169d0 T xTaskResumeAll\n"
	"00013660 T xmit_datablock\n"
;
