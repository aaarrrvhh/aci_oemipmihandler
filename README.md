# aci_oemipmihandler
for aci 2020.04 npcm750

Build the "oem-ipmi-handler" module:
bitbake oem-ipmi-handler

Test the IPMI command in the BMC console:
$ ipmitool -I dbus raw 0x32 0xBA
ff 00 aa 55
$ ipmitool -I lanplus -U ${username} -P ${password} -H ${bmc} raw 0x32 0xBA
ff 00 aa 55
$ ipmitool -I dbus raw 0x32 0xBE
55 aa 00 ff
$ ipmitool -I lanplus -U ${username} -P ${password} -H ${bmc} raw 0x32 0xBE
55 aa 00 ff





