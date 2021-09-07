#include "adcs.h"

ADCS_returnState HAL_ADCS_reset() { return ADCS_reset(); }

ADCS_returnState HAL_ADCS_reset_log_pointer() { return ADCS_reset_log_pointer(); }

ADCS_returnState HAL_ADCS_advance_log_pointer() { return ADCS_advance_log_pointer(); }

ADCS_returnState HAL_ADCS_reset_boot_registers() { return ADCS_reset_boot_registers(); }

ADCS_returnState HAL_ADCS_format_sd_card() { return ADCS_format_sd_card(); }

ADCS_returnState HAL_ADCS_erase_file(uint8_t file_type, uint8_t file_counter, bool erase_all) {
    return ADCS_erase_file(file_type, file_counter, erase_all);
}

ADCS_returnState HAL_ADCS_load_file_download_block(uint8_t file_type, uint8_t counter, uint32_t offset,
                                                   uint16_t block_length) {
    return ADCS_load_file_download_block(file_type, counter, offset, block_length);
}

ADCS_returnState HAL_ADCS_advance_file_list_read_pointer() { return ADCS_advance_file_list_read_pointer(); }

ADCS_returnState HAL_ADCS_initiate_file_upload(uint8_t file_dest, uint8_t block_size) {
    return ADCS_initiate_file_upload(file_dest, block_size);
}

ADCS_returnState HAL_ADCS_file_upload_packet(uint16_t packet_number, char *file_bytes) {
    return ADCS_file_upload_packet(packet_number, file_bytes);
}

ADCS_returnState HAL_ADCS_finalize_upload_block(uint8_t file_dest, uint32_t offset, uint16_t block_length) {
    return ADCS_finalize_upload_block(file_dest, offset, block_length);
}

ADCS_returnState HAL_ADCS_reset_upload_block() { return ADCS_reset_upload_block(); }

ADCS_returnState HAL_ADCS_reset_file_list_read_pointer() { return ADCS_reset_file_list_read_pointer(); }

ADCS_returnState HAL_ADCS_initiate_download_burst(uint8_t msg_length, bool ignore_hole_map) {
    return ADCS_initiate_download_burst(msg_length, ignore_hole_map);
}

ADCS_returnState HAL_ADCS_get_node_identification(ADCS_node_identification *node_id) {
    return ADCS_get_node_identification(&node_id->node_type, &node_id->interface_ver, &node_id->major_firm_ver,
                                        &node_id->minor_firm_ver, &node_id->runtime_s, &node_id->runtime_ms);
}

ADCS_returnState HAL_ADCS_get_boot_program_stat(ADCS_boot_program_stat *boot_program_stat) {
    return ADCS_get_boot_program_stat(&boot_program_stat->mcu_reset_cause, &boot_program_stat->boot_cause,
                                      &boot_program_stat->boot_count, &boot_program_stat->boot_idx);
}

ADCS_returnState HAL_ADCS_get_boot_index(ADCS_boot_index *boot_index) {
    return ADCS_get_boot_index(&boot_index->program_idx, &boot_index->boot_stat);
}

ADCS_returnState HAL_ADCS_get_last_logged_event(ADCS_last_logged_event *last_logged_event) {
    return ADCS_get_last_logged_event(&last_logged_event->time, &last_logged_event->event_id,
                                      &last_logged_event->event_param);
}

ADCS_returnState HAL_ADCS_get_SD_format_progress(bool *format_busy, bool *erase_all_busy) {
    return ADCS_get_SD_format_progress(format_busy, erase_all_busy);
}

ADCS_returnState HAL_ADCS_get_TC_ack(ADCS_TC_ack *TC_ack) {
    return ADCS_get_TC_ack(&TC_ack->last_tc_id, &TC_ack->tc_processed, &TC_ack->tc_err_stat, &TC_ack->tc_err_idx);
}

ADCS_returnState HAL_ADCS_get_file_download_buffer(uint16_t *packet_count, uint8_t **file[20]) {
    return ADCS_get_file_download_buffer(packet_count, file);
}

ADCS_returnState HAL_ADCS_get_file_download_block_stat(ADCS_file_download_block_stat *file_download_block_stat) {
    return ADCS_get_file_download_block_stat(
        &file_download_block_stat->ready, &file_download_block_stat->param_err,
        &file_download_block_stat->crc16_checksum, &file_download_block_stat->length);
}

ADCS_returnState HAL_ADCS_get_file_info(ADCS_file_info *file_info) {
    return ADCS_get_file_info(&file_info->type, &file_info->updating, &file_info->counter, &file_info->size,
                              &file_info->time, &file_info->crc16_checksum);
}

ADCS_returnState HAL_ADCS_get_init_upload_stat(bool *busy) { return ADCS_get_init_upload_stat(busy); }

ADCS_returnState HAL_ADCS_get_finalize_upload_stat(bool *busy, bool *err) {
    return ADCS_get_finalize_upload_stat(busy, err);
}

ADCS_returnState HAL_ADCS_get_upload_crc16_checksum(uint16_t *checksum) {
    return ADCS_get_upload_crc16_checksum(checksum);
}

ADCS_returnState HAL_ADCS_get_SRAM_latchup_count(ADCS_SRAM_latchup_count *SRAM_latchup_count) {
    return ADCS_get_SRAM_latchup_count(&SRAM_latchup_count->sram1, &SRAM_latchup_count->sram2);
}

ADCS_returnState HAL_ADCS_get_EDAC_err_count(ADCS_EDAC_err_count *EDAC_err_count) {
    return ADCS_get_EDAC_err_count(&EDAC_err_count->single_sram, &EDAC_err_count->double_sram,
                                   &EDAC_err_count->multi_sram);
}

ADCS_returnState HAL_ADCS_get_comms_stat(uint16_t *comm_status) {
    ADCS_returnState return_state;
    uint16_t TC_num = 0;
    uint16_t TM_num = 0;
    uint8_t flags_arr = 0;
    return_state = ADCS_get_comms_stat(comm_status, &TC_num, &TM_num, &flags_arr);

    return return_state;
}

ADCS_returnState HAL_ADCS_set_cache_en_state(bool en_state) { return ADCS_set_cache_en_state(en_state); }

ADCS_returnState HAL_ADCS_set_sram_scrub_size(uint16_t size) { return ADCS_set_sram_scrub_size(size); }

ADCS_returnState HAL_ADCS_set_UnixTime_save_config(uint8_t when, uint8_t period) {
    return ADCS_set_UnixTime_save_config(when, period);
}

ADCS_returnState HAL_ADCS_set_hole_map(uint8_t *hole_map, uint8_t num) { return ADCS_set_hole_map(hole_map, num); }

ADCS_returnState HAL_ADCS_set_unix_t(uint32_t unix_t, uint16_t count_ms) {
    return ADCS_set_unix_t(unix_t, count_ms);
}

ADCS_returnState HAL_ADCS_get_cache_en_state(bool *en_state) { return ADCS_get_cache_en_state(en_state); }

ADCS_returnState HAL_ADCS_get_sram_scrub_size(uint16_t *size) { return ADCS_get_sram_scrub_size(size); }

ADCS_returnState HAL_ADCS_get_UnixTime_save_config(ADCS_Unixtime_save_config *Unixtime_save_config) {
    return ADCS_get_UnixTime_save_config(&Unixtime_save_config->when, &Unixtime_save_config->period);
}

ADCS_returnState HAL_ADCS_get_hole_map(uint8_t *hole_map, uint8_t num) { return ADCS_get_hole_map(hole_map, num); }

ADCS_returnState HAL_ADCS_get_unix_t(ADCS_unix_t *A_unix_t) {
    return ADCS_get_unix_t(&A_unix_t->unix_t, &A_unix_t->count_ms);
}

ADCS_returnState HAL_ADCS_clear_err_flags() { return ADCS_clear_err_flags(); }

ADCS_returnState HAL_ADCS_set_boot_index(uint8_t index) { return ADCS_set_boot_index(index); }

ADCS_returnState HAL_ADCS_run_selected_program() { return ADCS_run_selected_program(); }

ADCS_returnState HAL_ADCS_read_program_info(uint8_t index) { return ADCS_read_program_info(index); }

ADCS_returnState HAL_ADCS_copy_program_internal_flash(uint8_t index, uint8_t overwrite_flag) {
    return ADCS_copy_program_internal_flash(index, overwrite_flag);
}

ADCS_returnState HAL_ADCS_get_bootloader_state(ADCS_bootloader_state *bootloader_state) {
    return ADCS_get_bootloader_state(&bootloader_state->uptime, &bootloader_state->flags_arr);
}

ADCS_returnState HAL_ADCS_get_program_info(ADCS_program_info *program_info) {
    return ADCS_get_program_info(&program_info->index, &program_info->busy, &program_info->file_size,
                                 &program_info->crc16_checksum);
}

ADCS_returnState HAL_ADCS_copy_internal_flash_progress(bool *busy, bool *err) {
    return HAL_ADCS_copy_internal_flash_progress(busy, err);
}

ADCS_returnState HAL_ADCS_deploy_magnetometer_boom(uint8_t actuation_timeout) {
    return ADCS_deploy_magnetometer_boom(actuation_timeout);
}

ADCS_returnState HAL_ADCS_set_enabled_state(uint8_t state) { return ADCS_set_enabled_state(state); }

ADCS_returnState HAL_ADCS_clear_latched_errs(bool adcs_flag, bool hk_flag) {
    return ADCS_clear_latched_errs(adcs_flag, hk_flag);
}

ADCS_returnState HAL_ADCS_set_attitude_ctrl_mode(uint8_t ctrl_mode, uint16_t timeout) {
    return ADCS_set_attitude_ctrl_mode(ctrl_mode, timeout);
}

ADCS_returnState HAL_ADCS_set_attitude_estimate_mode(uint8_t mode) {
    return ADCS_set_attitude_estimate_mode(mode);
}

ADCS_returnState HAL_ADCS_trigger_adcs_loop() { return ADCS_trigger_adcs_loop(); }

ADCS_returnState HAL_ADCS_trigger_adcs_loop_sim(sim_sensor_data sim_data) {
    return ADCS_trigger_adcs_loop_sim(sim_data);
}

ADCS_returnState HAL_ADCS_set_ASGP4_rune_mode(uint8_t mode) { return ADCS_set_ASGP4_rune_mode(mode); }

ADCS_returnState HAL_ADCS_trigger_ASGP4() { return ADCS_trigger_ASGP4(); }

ADCS_returnState HAL_ADCS_set_MTM_op_mode(uint8_t mode) { return ADCS_set_MTM_op_mode(mode); }

ADCS_returnState HAL_ADCS_cnv2jpg(uint8_t source, uint8_t QF, uint8_t white_balance) {
    return ADCS_cnv2jpg(source, QF, white_balance);
}

ADCS_returnState HAL_ADCS_save_img(uint8_t camera, uint8_t img_size) { return ADCS_save_img(camera, img_size); }

ADCS_returnState HAL_ADCS_set_magnetorquer_output(xyz16 duty_cycle) {
    return ADCS_set_magnetorquer_output(duty_cycle);
}

ADCS_returnState HAL_ADCS_set_wheel_speed(xyz16 speed) { return ADCS_set_wheel_speed(speed); }

ADCS_returnState HAL_ADCS_save_config() { return ADCS_save_config(); }

ADCS_returnState HAL_ADCS_save_orbit_params() { return ADCS_save_orbit_params(); }

ADCS_returnState HAL_ADCS_get_current_state(adcs_state *data) { return ADCS_get_current_state(data); }

ADCS_returnState HAL_ADCS_get_jpg_cnv_progress(ADCS_jpg_cnv_progress *jpg_cnv_progress) {
    return ADCS_get_jpg_cnv_progress(&jpg_cnv_progress->percentage, &jpg_cnv_progress->result,
                                     &jpg_cnv_progress->file_counter);
}

ADCS_returnState HAL_ADCS_get_cubeACP_state(uint8_t *flags_arr) { return ADCS_get_cubeACP_state(flags_arr); }

ADCS_returnState HAL_ADCS_get_execution_times(ADCS_execution_times *execution_times) {
    return ADCS_get_execution_times(&execution_times->adcs_update, &execution_times->sensor_comms,
                                    &execution_times->sgp4_propag, &execution_times->igrf_model);
}

ADCS_returnState HAL_ADCS_get_ACP_loop_stat(ADCS_ACP_loop_stat *ACP_loop_stat) {
    return ADCS_get_ACP_loop_stat(&ACP_loop_stat->time, &ACP_loop_stat->execution_point);
}

ADCS_returnState HAL_ADCS_get_sat_pos_LLH(xyz *target) { return ADCS_get_sat_pos_LLH(target); }

ADCS_returnState HAL_ADCS_get_img_save_progress(ADCS_img_save_progress *img_save_progress) {
    return ADCS_get_img_save_progress(&img_save_progress->percentage, &img_save_progress->status);
}

ADCS_returnState HAL_ADCS_get_measurements(adcs_measures *measurements) {
    return ADCS_get_measurements(measurements);
}

ADCS_returnState HAL_ADCS_get_actuator(adcs_actuator *commands) { return ADCS_get_actuator(commands); }

ADCS_returnState HAL_ADCS_get_estimation(adcs_estimate *data) { return ADCS_get_estimation(data); }

ADCS_returnState HAL_ADCS_get_ASGP4(bool *complete, uint8_t *err, adcs_asgp4 *asgp4) {
    return ADCS_get_ASGP4(complete, err, asgp4);
}

ADCS_returnState HAL_ADCS_get_raw_sensor(adcs_raw_sensor *measurements) {
    return ADCS_get_raw_sensor(measurements);
}

ADCS_returnState HAL_ADCS_get_raw_GPS(adcs_raw_gps *measurements) { return ADCS_get_raw_GPS(measurements); }

ADCS_returnState HAL_ADCS_get_star_tracker(adcs_star_track *measurements) {
    return ADCS_get_star_tracker(measurements);
}

ADCS_returnState HAL_ADCS_get_MTM2_measurements(xyz16 *Mag) { return ADCS_get_MTM2_measurements(Mag); }

ADCS_returnState HAL_ADCS_get_power_temp(adcs_pwr_temp *measurements) { return ADCS_get_power_temp(measurements); }

ADCS_returnState HAL_ADCS_set_power_control(uint8_t *control) { return ADCS_set_power_control(control); }

ADCS_returnState HAL_ADCS_get_power_control(uint8_t *control) { return ADCS_get_power_control(control); }

ADCS_returnState HAL_ADCS_set_attitude_angle(xyz att_angle) { return ADCS_set_attitude_angle(att_angle); }

ADCS_returnState HAL_ADCS_get_attitude_angle(xyz *att_angle) { return ADCS_get_attitude_angle(att_angle); }

ADCS_returnState HAL_ADCS_set_track_controller(xyz target) { return ADCS_set_track_controller(target); }

ADCS_returnState HAL_ADCS_get_track_controller(xyz *target) { return ADCS_get_track_controller(target); }

ADCS_returnState HAL_ADCS_set_log_config(uint8_t **flags_arr[10], uint16_t period, uint8_t dest, uint8_t log) {
    return ADCS_set_log_config(flags_arr, period, dest, log);
}

ADCS_returnState HAL_ADCS_get_log_config(uint8_t **flags_arr[10], uint16_t *period, uint8_t *dest, uint8_t log) {
    return ADCS_get_log_config(flags_arr, period, dest, log);
}

ADCS_returnState HAL_ADCS_set_inertial_ref(xyz iner_ref) { return ADCS_set_inertial_ref(iner_ref); }

ADCS_returnState HAL_ADCS_get_inertial_ref(xyz *iner_ref) { return ADCS_get_inertial_ref(iner_ref); }

ADCS_returnState HAL_ADCS_set_sgp4_orbit_params(adcs_sgp4 params) { return ADCS_set_sgp4_orbit_params(params); }

ADCS_returnState HAL_ADCS_get_sgp4_orbit_params(adcs_sgp4 *params) { return ADCS_get_sgp4_orbit_params(params); }

ADCS_returnState HAL_ADCS_set_system_config(adcs_sysConfig config) { return ADCS_set_system_config(config); }

ADCS_returnState HAL_ADCS_get_system_config(adcs_sysConfig *config) { return ADCS_get_system_config(config); }

ADCS_returnState HAL_ADCS_set_MTQ_config(xyzu8 params) { return ADCS_set_MTQ_config(params); }

ADCS_returnState HAL_ADCS_set_RW_config(uint8_t *RW) { return ADCS_set_RW_config(RW); }

ADCS_returnState HAL_ADCS_set_rate_gyro(rate_gyro_config params) { return ADCS_set_rate_gyro(params); }

ADCS_returnState HAL_ADCS_set_css_config(css_config config) { return ADCS_set_css_config(config); }

ADCS_returnState HAL_ADCS_set_star_track_config(cubestar_config config) {
    return ADCS_set_star_track_config(config);
}

ADCS_returnState HAL_ADCS_set_cubesense_config(cubesense_config params) {
    return ADCS_set_cubesense_config(params);
}

ADCS_returnState HAL_ADCS_set_mtm_config(mtm_config params, uint8_t mtm) {
    return ADCS_set_mtm_config(params, mtm);
}

ADCS_returnState HAL_ADCS_set_detumble_config(detumble_config config) { return ADCS_set_detumble_config(config); }

ADCS_returnState HAL_ADCS_set_ywheel_config(ywheel_ctrl_config params) { return ADCS_set_ywheel_config(params); }

ADCS_returnState HAL_ADCS_set_rwheel_config(rwheel_ctrl_config params) { return ADCS_set_rwheel_config(params); }

ADCS_returnState HAL_ADCS_set_tracking_config(track_ctrl_config params) {
    return ADCS_set_tracking_config(params);
}

ADCS_returnState HAL_ADCS_set_MoI_mat(moment_inertia_config cell) { return ADCS_set_MoI_mat(cell); }

ADCS_returnState HAL_ADCS_set_estimation_config(estimation_config config) {
    return ADCS_set_estimation_config(config);
}

ADCS_returnState HAL_ADCS_set_usercoded_setting(usercoded_setting setting) {
    return ADCS_set_usercoded_setting(setting);
}

ADCS_returnState HAL_ADCS_set_asgp4_setting(aspg4_setting setting) { return ADCS_set_asgp4_setting(setting); }

ADCS_returnState HAL_ADCS_get_full_config(adcs_config *config) { return ADCS_get_full_config(config); }

ADCS_returnState HAL_ADCS_getHK(ADCS_HouseKeeping *adcs_hk) {
    ADCS_returnState temp;
    ADCS_returnState return_state = 0;
    adcs_state data;
    adcs_measures mes;
    adcs_pwr_temp pwr;
    xyz pos;

    if (temp = HAL_ADCS_get_current_state(&data) != 0) {
        return_state = temp;
    } else {
        // adcs_hk->Estimated_Angular_Rate = data.est_angular_rate;
        adcs_hk->Estimated_Angular_Rate_X = data.est_angular_rate.x;
        adcs_hk->Estimated_Angular_Rate_Y = data.est_angular_rate.y;
        adcs_hk->Estimated_Angular_Rate_Z = data.est_angular_rate.z;
        // adcs_hk->Estimated_Angular_Angle = data.est_angle;
        adcs_hk->Estimated_Angular_Angle_X = data.est_angle.x;
        adcs_hk->Estimated_Angular_Angle_Y = data.est_angle.y;
        adcs_hk->Estimated_Angular_Angle_Z = data.est_angle.z;
        // adcs_hk->Sat_Position_ECI = data.ECI_pos;
        adcs_hk->Sat_Position_ECI_X = data.ECI_pos.x;
        adcs_hk->Sat_Position_ECI_Y = data.ECI_pos.y;
        adcs_hk->Sat_Position_ECI_Z = data.ECI_pos.z;
        // adcs_hk->Sat_Velocity_ECI = data.ECI_vel;
        adcs_hk->Sat_Velocity_ECI_X = data.ECI_vel.x;
        adcs_hk->Sat_Velocity_ECI_Y = data.ECI_vel.y;
        adcs_hk->Sat_Velocity_ECI_Z = data.ECI_vel.z;
        // adcs_hk->ECEF_Position = data.ecef_pos;
        adcs_hk->ECEF_Position_X = data.ecef_pos.x;
        adcs_hk->ECEF_Position_Y = data.ecef_pos.y;
        adcs_hk->ECEF_Position_Z = data.ecef_pos.z;
    }

    if (temp = HAL_ADCS_get_measurements(&mes) != 0) {
        return_state = temp;
    } else {
        // adcs_hk->Coarse_Sun_Vector = mes.coarse_sun;
        adcs_hk->Coarse_Sun_Vector_X = mes.coarse_sun.x;
        adcs_hk->Coarse_Sun_Vector_Y = mes.coarse_sun.y;
        adcs_hk->Coarse_Sun_Vector_Z = mes.coarse_sun.z;
        // adcs_hk->Fine_Sun_Vector = mes.sun;
        adcs_hk->Fine_Sun_Vector_X = mes.sun.x;
        adcs_hk->Fine_Sun_Vector_Y = mes.sun.y;
        adcs_hk->Fine_Sun_Vector_Z = mes.sun.z;
        // adcs_hk->Nadir_Vector = mes.nadir;
        adcs_hk->Nadir_Vector_X = mes.nadir.x;
        adcs_hk->Nadir_Vector_Y = mes.nadir.y;
        adcs_hk->Nadir_Vector_Z = mes.nadir.z;
        // adcs_hk->Wheel_Speed = mes.wheel_speed;
        adcs_hk->Wheel_Speed_X = mes.wheel_speed.x;
        adcs_hk->Wheel_Speed_Y = mes.wheel_speed.y;
        adcs_hk->Wheel_Speed_Z = mes.wheel_speed.z;
        // adcs_hk->Mag_Field_Vector = mes.magnetic_field;
        adcs_hk->Mag_Field_Vector_X = mes.magnetic_field.x;
        adcs_hk->Mag_Field_Vector_Y = mes.magnetic_field.y;
        adcs_hk->Mag_Field_Vector_Z = mes.magnetic_field.z;
    }

    if (temp = HAL_ADCS_get_power_temp(&pwr) != 0) {
        return_state = temp;
    } else {
        adcs_hk->Wheel1_Current = pwr.wheel1_I;
        adcs_hk->Wheel2_Current = pwr.wheel2_I;
        adcs_hk->Wheel3_Current = pwr.wheel3_I;
        adcs_hk->CubeSense1_Current = pwr.cubesense1_3v3_I;
        adcs_hk->CubeSense2_Current = pwr.cubesense2_3v3_I;
        adcs_hk->CubeControl_Current3v3 = pwr.cubecontrol_3v3_I;
        adcs_hk->CubeControl_Current5v0 = pwr.cubecontrol_5v_I;
        adcs_hk->CubeStar_Current = pwr.cubestar_I;
        adcs_hk->Magnetorquer_Current = pwr.magnetorquer_I;
        adcs_hk->CubeStar_Temp = pwr.cubestar_temp;
        adcs_hk->MCU_Temp = pwr.MCU_temp;
        // adcs_hk->Rate_Sensor_Temp = pwr.rate_sensor_temp;
        adcs_hk->Rate_Sensor_Temp_X = pwr.rate_sensor_temp.x;
        adcs_hk->Rate_Sensor_Temp_Y = pwr.rate_sensor_temp.y;
        adcs_hk->Rate_Sensor_Temp_Z = pwr.rate_sensor_temp.z;
    }

    // if (temp = HAL_ADCS_get_sat_pos_LLH(&adcs_hk->Sat_Position_LLH) != 0) return_state = temp;
    if (temp = HAL_ADCS_get_sat_pos_LLH(&pos) != 0) {
        return_state = temp;
    } else {
        adcs_hk->Sat_Position_LLH_X = pos.x;
        adcs_hk->Sat_Position_LLH_Y = pos.y;
        adcs_hk->Sat_Position_LLH_Z = pos.z;
    }

    if (temp = HAL_ADCS_get_comms_stat(&adcs_hk->Comm_Status) != 0)
        return_state = temp;

    return return_state;
}
