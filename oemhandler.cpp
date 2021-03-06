#include <ipmid/api.h>
#include <iostream>

// Declares register function with attribute "constructor".
void register_netfn_oem_functions() __attribute__((constructor));

// Callback function for handling Oem command 0xBA.
ipmi_ret_t ipmi_my_handler1(ipmi_netfn_t netfn, ipmi_cmd_t cmd,
ipmi_request_t request, ipmi_response_t response,
ipmi_data_len_t data_len, ipmi_context_t context)
{
    std::cout << __FUNCTION__ << " entered! " << std::endl;
    ipmi_ret_t rc = IPMI_CC_OK;
    uint8_t rsp[] = {0xFF, 0x00, 0xAA, 0x55};
    memcpy(response, &rsp, 4);
    *data_len = 4;
    return rc;
}
// Callback function for handling OEM command 0xBE.
ipmi_ret_t ipmi_my_handler2(ipmi_netfn_t netfn, ipmi_cmd_t cmd,
ipmi_request_t request, ipmi_response_t response,
ipmi_data_len_t data_len, ipmi_context_t context)
{
    std::cout << __FUNCTION__ << " entered! " << std::endl;
    ipmi_ret_t rc = IPMI_CC_OK;
    uint8_t rsp[] = {0x55, 0xAA, 0x00, 0xFF};
    memcpy(response, &rsp, 4);
    *data_len = 4;
    return rc;
}
// Register function
void register_netfn_oem_functions()
{
    std::cout << "Registering OEM command handlers" << std::endl;
    ipmi_register_callback(NETFUN_OEM, 0xBA, NULL, ipmi_my_handler1, PRIVILEGE_USER);
    ipmi_register_callback(NETFUN_OEM, 0xBE, NULL, ipmi_my_handler2, PRIVILEGE_USER);
    return;
}
