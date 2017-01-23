# psvcmd56  
Reversed code of PS Vita SD card and related drivers  
  
# Description of CMD56 protocol  
  
Custom SD card initialization is implemented with CMD56 SD command  
that allows to send vendor specific data to the card ad from card  
  
Custom initialization involves 'xyz wiki: New Vita Kirk services'  
https://wiki.henkaku.xyz/vita/F00D_Commands#0x1000B  
  
Initialization starts from request packet that is sent to SD card  
  
## Request packet layout  
  
Any request packet can be split into 4 main parts  
0x20 bytes - constant chunk   
0x0C bytes - request data header1  
0x03 bytes - request data header2  
  N  bytes - data  
  
## packet 1  
  
Length of packet1 is 0x2F bytes.  
Layout is the following:  
  
packet1: - constant  
0x00 - 0x20 : DD1025441523FDC0F9E91526DC2AE084A903A297D4BBF852D3D4942C8903CC77 - constant chunk of 0x20 bytes  
0x20 - 0x24 : 31000000 - response code that we expect in packet2  
0x24 - 0x28 : 03000000 - size of additional request data  
0x28 - 0x2C : 13000000 - size of response data that we expect  
0x2C - 0x2F : C4 00 03 - request data of size 0x03  
  
Layout of request data is:  
0x2C - C4 - ?  
0x2D - 00 - ?  
0x2E - 03 - size of additional request data  
  
## packet 2  
  
packet2: - constant  
0x00: 31000000 - response code  
0x04: 00000000 - ?  
0x08: 00 13 - size of response data including these 2 bytes (big endian)  
0x0A: 00 - error code  
0x0B: 00 00 00 00 00 00 00 00 00 00 00 00 00 01 01 04 - chunk of 0x10 bytes  
  
byte 0x00 - must be 0x31 - this is some kind of response code that we send in packet1 and expect to be the same in response packet2  
byte 0x04 - must be 0x00 - ?  
byte 0x0A - must be 0x00 - this is some kind of error code  
  
## packet 3  
  
packet3: - constant  
0x00 - 0x20 : DD1025441523FDC0F9E91526DC2AE084A903A297D4BBF852D3D4942C8903CC77 - constant chunk of 0x20 bytes  
0x20 - 0x24 : 23000000 - response code that we expect in packet4  
0x24 - 0x28 : 03000000 - size of additional request data  
0x28 - 0x2C : 05000000 - size of response data that we expect  
0x2C - 0x2F : C2 00 03 - request data of size 0x03  
  
Layout of request data is:  
0x2C - C2 - ?  
0x2D - 00 - ?  
0x2E - 03 - size of additional request data  
  
## packet 4  
  
packet4: - constant  
0x00: 23000000 - response code  
0x04: 00000000 - ?  
0x08: 00 05 - size of response data including these 2 bytes (big endian)  
0x0A: 00 - error code  
0x0B: FF 00 - chunk of 0x02 bytes  
  
byte 0x00 - must be 0x23 - this is some kind of response code that we send in packet3 and expect to be the same in response packet4  
byte 0x04 - must be 0x00 - ?  
byte 0x0A - must be 0x00 - this is some kind of error code  
  
## packet 5  
  
packet5: - constant  
0x00 - 0x20 : DD1025441523FDC0F9E91526DC2AE084A903A297D4BBF852D3D4942C8903CC77 - constant chunk of 0x20 bytes  
0x20 - 0x24 : 02000000 - response code that we expect in packet6  
0x24 - 0x28 : 03000000 - size of additional request data  
0x28 - 0x2C : 2B000000 - size of response data that we expect  
0x2C - 0x2F : A1 00 03 - request data of size 0x03  
  
Layout of request data is:  
0x2C - A1 - ?  
0x2D - 00 - ?  
0x2E - 03 - size of additional request data  
  
## packet 6  
  
packet6: - constant  
0x00: 02000000 - response code  
0x04: 00000000 - ?  
0x08: 00 2B - size of response data including these 2 bytes (big endian)  
0x0A: 00 - error code  
0x0B: E0 00   
0x0D: 00 01 - value of 0x02 bytes (big endian)  
0x0F: 00 02 - ?  
0x11: 00 03 - ?  
0x13: 00010001000000000000000100FE95F2 C273E9454208005FE8560799DDF91F9F - chunk of 0x20 bytes  
  
byte 0x00 - must be 0x02 - this is some kind of response code that we send in packet5 and expect to be the same in response packet6  
byte 0x04 - must be 0x00  
byte 0x0A - must be 0x00 - this is some kind of error code  
  
chunk of 0x20 bytes from offset 0x13 is copied to _00BDCFF8  
  
bytes 0x0D and 0x0E are transformed this way:  
_00BDCDF4_PACKET6_DE = (byte 0xE) | ((byte 0xD) << 8) = 0001  
  
## packet 7  
  
packet7: - partially constant  
0x00 - 0x20 : DD1025441523FDC0F9E91526DC2AE084A903A297D4BBF852D3D4942C8903CC77 - constant chunk of 0x20 bytes  
0x20 - 0x24 : 03000000 - response code that we expect in packet8  
0x24 - 0x28 : 15000000 - size of additional request data  
0x28 - 0x2C : 23000000 - size of response data that we expect  
0x2C - 0x2F : A2 00 15 | ?? ?? | ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - request data of size 0x15  
  
Layout of request data is:  
0x2C - A2 - ?  
0x2D - 00 - ?  
0x2E - 15 - size of additional request data  
0x2F - 00 01 - value of 0x02 bytes (from packet6) (from card)  
0x31 - 0x41 : ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - chunk of 0x10 bytes  
  
chunk of 0x10 bytes starting from offset 0x31 is generated with sub_CA8E5C  
then first byte is modified as: byte = (byte | (~0x7F))  
  
bytes 0x2F and 0x30 are transformed this way:  
byte 0x2F = _00BDCDF4_PACKET6_DE >> 8 = 00  
byte 0x30 = _00BDCDF4_PACKET6_DE = 01  
  
## packet 8  
  
packet8: - partially constant  
0x00: 03000000 - response code  
0x04: 00000000 - ?  
0x08: ?? ?? - size of response data (expected 00 23)  
0x0A: ?? - error code (expected 00)  
0x0B: ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - chunk of 0x20 bytes  
  
byte 0x00 - must be 0x03 - this is some kind of response code that we send in packet7 and expect to be the same in response packet8  
byte 0x04 - must be 0x00  
byte 0x0A - must be 0x00 - this is some kind of error code  
  
## packet 9  
  
packet9: - partially constant  
  
Here starts first communication with New KIRK service  
Communication is done through sub_CAC924  
which is a wrapper for SceSblSsSmComm   
which is a wrapper for SceSblSmschedProxy   
which is a wrapper for SMC calls to Trusted zone lv1  
where I suppose happens call to F00D lv0  
  
signature is:  
int sub_CAC924(char* destination, char* source, int command, int size, int packet6_de)  
  
packet that is sent is 0x53 bytes long  
as temp buffer 'input_buffer' is used  
  
0x00 - 0x20 - data from _00BDCFF8 (from packet6) (from card) - 0x20 bytes  
0x20 - 0x30 - data generated with sub_CA8E5C (from packet7) - 0x10 bytes  
0x30 - 0x53 - data from packet8 (from card) at offset 0x08 - 0x23 bytes  
  
call sub_CAC924(0, input_buffer, KIRK_SERVICE_1B, 0x53, _00BDCDF4_PACKET6_DE)  
  
This should call Kirk service 1B for 1000B (xyz wiki - "New Vita Kirk 0x1B service. Unknown, but buffer length is 0x53")  
request size - 0x53  
response size - no response  
  
As this request has no response I assume that this is some data verification call  
  
packet that is sent is 0x40 bytes long  
as temp buffer 'input_buffer' is used  
_00BDCDF8_WB20 is used as 'output_buffer'  
  
0x00 - 0x20 - data from _00BDCFF8 (from packet6) (from card) - 0x20 bytes  
0x20 - 0x40 - data from packet8 at offset 0x0B - 0x20 bytes  
  
sub_CAC924(output_buffer, input_buffer, KIRK_SERVICE_1C, 0x40, _00BDCDF4_PACKET6_DE);  
  
This should call Kirk service 1C for 1000B (xyz wiki - "New Vita Kirk 0x1C service. Unknown, but buffer length is 0x40")  
request size - 0x40  
response size - 0x33 (this is validated by sub_CAC924)  
  
As this request has a response I assume that this is some data generation call  
  
data generated by Kirk is 0x33 bytes long and is stored into _00BDCDF8_WB20  
which is a buffer that is copied to all request packets, starting from offset 0x24  
  
I am not sure what is this data but based on knowledge about packet9 I can say that layout  should be:  
0x00 - ?? - ?  
0x01 - ?? - ?  
0x02 - 33 - size of additional request data  
0x03 - 0x30 : ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ??  
  
After that:  
0x30 bytes starting from offset 0x03 are copied to _00BDCBC4 (Data generated by Kirk service 1C)  
  
Now packet9 is assembled:  
0x00 - 0x20 : DD1025441523FDC0F9E91526DC2AE084A903A297D4BBF852D3D4942C8903CC77 - constant chunk of 0x20 bytes  
0x20 - 0x24 : 05000000 - response code that we expect in packet10  
0x24 - 0x28 : 33000000 - size of additional request data  
0x28 - 0x2C : 03000000 - size of response data that we expect  
0x2C - 0x5F : ?? ?? ?? | ?? ... ?? - Data generated by Kirk service 1C - chunk if 0x33 bytes  
  
## packet 10  
  
packet10: - constant  
0x00: 05000000 - response code  
0x04: 00000000 - ?  
0x08: 00 03 - size of response data  
0x0A: 00 - error code  
  
byte 0x00 - must be 0x05 - this is some kind of response code that we send in packet9 and expect to be the same in response packet10  
byte 0x04 - must be 0x00  
byte 0x0A - must be 0x00 - this is some kind of error code  
  
## packet 11  
  
packet11: - constant - same as packet3  
0x00 - 0x20 : DD1025441523FDC0F9E91526DC2AE084A903A297D4BBF852D3D4942C8903CC77 - constant chunk of 0x20 bytes  
0x20 - 0x24 : 23000000 - response code that we expect in packet12  
0x24 - 0x28 : 03000000 - size of additional request data  
0x28 - 0x2C : 05000000 - size of response data that we expect  
0x2C - 0x2F : C2 00 03 - request data of size 0x03  
  
Layout of request data is:  
0x2C - C2 - ?  
0x2D - 00 - ?  
0x2E - 03 - size of additional request data  
  
## packet 12  
  
packet12: - constant - same as packet4 (except for bytes 0x0B 0x0C)  
0x00: 23000000 - response code  
0x04: 00000000 - ?  
0x08: 00 05 - size of response data including these 2 bytes (big endian)  
0x0A: 00 - error code  
0x0B: 00 00 - chunk of 0x02 bytes  
  
byte 0x00 - must be 0x23 - this is some kind of response code that we send in packet3 and expect to be the same in response packet4  
byte 0x04 - must be 0x00 - ?  
byte 0x0A - must be 0x00 - this is some kind of error code  
  
## packet 13  
  
packet13: - partially constant  
0x00 - 0x20 : DD1025441523FDC0F9E91526DC2AE084A903A297D4BBF852D3D4942C8903CC77  
0x20 - 0x24 : 07000000 - response code that we expect in packet14  
0x24 - 0x28 : 13000000 - size of additional request data  
0x28 - 0x2C : 43000000 - size of response data that we expect  
0x2C - 0x3F : A4 00 13 | ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - request data of size 0x13  
  
Layout of request data is:  
0x2C - A4 - ?  
0x2D - 00 - ?  
0x2E - 13 - size of additional request data  
0x2F - 0x3F : ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - chunk of 0x10 bytes  
  
chunk of 0x10 bytes starting from offset 0x2F is generated with sub_CA8E5C  
then first byte is modified as: byte = (byte | (~0x7F))  
  
after packet is sent:  
chunk of 0x10 bytes from offset 0x2F is copied from request to arg24  
  
## packet 14  
  
packet14: - partially constant  
0x00: 07000000 - response code  
0x04: 00000000 - ?  
0x08: ?? ?? - size of response data (expected 00 43)  
0x0A: ?? - error code (expected 00)  
0x0B: ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - chunk of 0x40 bytes  
  
byte 0x00 - must be 0x07 - this is some kind of response code that we send in packet13 and expect to be the same in response packet14  
byte 0x04 - must be 0x00 - ?  
byte 0x0A - must be 0x00 - this is some kind of error code  
  
## packet 15  
  
packet15: - partially constant  
  
Here communication with Kirk happens again  
  
packet that is sent is 0xA3 bytes long  
as temp buffer 'arg44' is used  
  
0x00 - 0x20 - data from _00BDCFF8 (from packet6) (from card) - 0x20 bytes  
0x20 - 0x50 - data from _00BDCBC4 (from Kirk service 1C) - 0x30 bytes  
0x50 - 0x60 - data from arg24 (from packet13 generated with sub_CA8E5C) - 0x10 bytes  
0x60 - 0xA3 - data from packet14 (from card) starting at offset 0x08 - 0x43 bytes  
  
call sub_CAC924(0, arg44, KIRK_SERVICE_1D, 0xA3, _00BDCDF4_PACKET6_DE)  
  
This should call Kirk service 1D for 1000B (xyz wiki "New Vita Kirk 0x1D service. Unknown, but buffer length is 0xA3. Related to SceSdif somehow.")  
request size - 0xA3  
response size - no response  
  
As this request has no response I assume that this is some data verification call  
  
packet that is sent is 0x51 bytes long  
as temp buffer 'data_buffer' is used  
  
0x00 - 0x20 - data from _00BDCFF8 (from packet6) (from card) - 0x20 bytes  
0x20 - 0x50 - data from _00BDCBC4 (from Kirk service 1C) - 0x30 bytes  
0x50 - 0x51 - 0x02 - constant  
  
call sub_CAC924(a_00BDCDF8_WB20, data_buffer, KIRK_SERVICE_1E, 0x51, packet6_de)  
  
This should call Kirk service 1E for 1000B (xyz wiki "New Vita Kirk 0x1E service. Unknown, but buffer length is 0x51. Related to SceSdif somehow.")  
request size - 0x51  
response size - 0x33 (this is validated by sub_CAC924)  
  
As this request has a response I assume that this is some data generation call  
  
data generated by Kirk is 0x33 bytes long and is stored into _00BDCDF8_WB20  
which is a buffer that is copied to all request packets, starting from offset 0x24  
  
I am not sure what is this data but based on knowledge about packet15 I can say that layout should be:  
0x00 - ?? - ?  
0x01 - ?? - ?  
0x02 - 33 - size of additional request data  
0x03 - 0x30 : ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ??  
  
Now packet15 is assembled:  
0x00 - 0x20 : DD1025441523FDC0F9E91526DC2AE084A903A297D4BBF852D3D4942C8903CC77 - constant chunk of 0x20 bytes  
0x20 - 0x24 : 11000000 - response code that we expect in packet16  
0x24 - 0x28 : 33000000 - size of additional request data  
0x28 - 0x2C : 43000000 - size of response data that we expect  
0x2C - 0x5C : ?? ?? ?? | ?? ... ?? - Data generated by Kirk service 1E - chunk if 0x33 bytes  
  
after packet is sent:  
chunk of 0x20 bytes from offset 0x2F is copied from request to arg24 (Data generated by Kirk service 1E)  
I am not sure why last 0x10 bytes are not copied  
Maybe this is somehow related to byte 0x51 of request data to Kirk service 1E?  
  
## packet 16  
  
packet16: - partially constant  
0x00: 11000000 - response code  
0x04: 00000000 - ?  
0x08: ?? ?? - size of response data (expected 00 43)  
0x0A: ?? - error code (expected 00)  
0x0B: ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - chunk of 0x40 bytes  
  
byte 0x00 - must be 0x11 - this is some kind of response code that we send in packet15 and expect to be the same in response packet16  
byte 0x04 - must be 0x00 - ?  
byte 0x0A - must be 0x00 - this is some kind of error code  
  
## packet 17  
  
packet17: - partially constant  
  
Here communication with Kirk happens again  
  
packet that is sent is 0xB3 bytes long  
as temp buffer 'arg44' is used  
  
0x00 - 0x20 - data from _00BDCFF8 (from packet6) (from card) - 0x20 bytes  
0x20 - 0x50 - data from _00BDCBC4 (from Kirk service 1C) - 0x30 bytes  
0x50 - 0x70 - data from arg24 (from Kirk service 1E - partial) - 0x20 bytes  
0x70 - 0xB3 - data from packet16 (from card) starting at offset 0x08 - 0x43 bytes  
  
call sub_CAC924(_00BDD44C, arg44, KIRK_SERVICE_1F, 0xB3, _00BDCDF4_PACKET6_DE)  
  
This should call Kirk service 1F for 1000B (xyz wiki "New Vita Kirk 0x1F service. Unknown, but buffer length is 0xB3. Related to SceSdif somehow.")  
request size - 0xB3  
response size - 0x20 (this is validated by sub_CAC924)  
  
I am not sure if _00BDD44C is used somewhere so I do not know if this a data validation or data generation call  
Maybe it changes 0x20 bytes from Kirk service 1E and returns them ?  
  
The only other 1 place where _00BDD44C is used are:  
SceSblGcAuthMgrDrmBBForDriver_bb451e83 - this function clears sensitive data from buffers  
  
packet that is sent is 0x51 bytes long  
as temp buffer 'data_buffer' is used  
  
0x00 - 0x20 - data from _00BDCFF8 (from packet6) (from card) - 0x20 bytes  
0x20 - 0x50 - data from _00BDCBC4 (from Kirk service 1C) - 0x30 bytes  
0x50 - 0x51 - 0x03 - constant  
  
call sub_CAC924(a_00BDCDF8_WB20, data_buffer, KIRK_SERVICE_1E, 0x51, packet6_de)  
  
This should call Kirk service 1E for 1000B (xyz wiki "New Vita Kirk 0x1E service. Unknown, but buffer length is 0x51. Related to SceSdif somehow.")  
request size - 0x51  
response size - 0x33 (this is validated by sub_CAC924)  
  
As this request has a response I assume that this is some data generation call  
  
data generated by Kirk is 0x33 bytes long and is stored into _00BDCDF8_WB20  
which is a buffer that is copied to all request packets, starting from offset 0x24  
  
I am not sure what is this data but based on knowledge about packet17 I can say that layout should be:  
0x00 - ?? - ?  
0x01 - ?? - ?  
0x02 - 33 - size of additional request data  
0x03 - 0x30 : ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ??  
  
Now packet17 is assembled:  
0x00 - 0x20 : DD1025441523FDC0F9E91526DC2AE084A903A297D4BBF852D3D4942C8903CC77 - constant chunk of 0x20 bytes  
0x20 - 0x24 : 11000000 - response code that we expect in packet18  
0x24 - 0x28 : 33000000 - size of additional request data  
0x28 - 0x2C : 43000000 - size of response data that we expect  
0x2C - 0x5C : ?? ?? ?? | ?? ... ?? - Data generated by Kirk service 1E - chunk if 0x33 bytes  
  
after packet is sent:  
chunk of 0x20 bytes from offset 0x2F is copied from request to var15C (Data generated by Kirk service 1E)  
I am not sure why last 0x10 bytes are not copied  
Maybe this is somehow related to byte 0x51 of request data to Kirk service 1E?  
  
## packet 18  
  
packet18: - partially constant  
0x00: 11000000 - response code  
0x04: 00000000 - ?  
0x08: ?? ?? - size of response data (expected 00 43)  
0x0A: ?? - error code (expected 00)  
0x0B: ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - chunk of 0x40 bytes  
  
byte 0x00 - must be 0x11 - this is some kind of response code that we send in packet15 and expect to be the same in response packet16  
byte 0x04 - must be 0x00 - ?  
byte 0x0A - must be 0x00 - this is some kind of error code  
  
## packet 19  
  
packet19: - partially constant  
0x00 - 0x20 : DD1025441523FDC0F9E91526DC2AE084A903A297D4BBF852D3D4942C8903CC77  
0x20 - 0x24 : 19000000 - response code that we expect in packet20  
0x24 - 0x28 : 13000000 - size of additional request data  
0x28 - 0x2C : 53000000 - size of response data that we expect  
0x2C - 0x3F : C1 00 13 | ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - request data of size 0x13  
  
Layout of request data is:  
0x2C - C1 - ?  
0x2D - 00 - ?  
0x2E - 13 - size of additional request data  
0x2F - 0x3F : ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - chunk of 0x10 bytes  
  
chunk of 0x10 bytes starting from offset 0x2F is generated with sub_CA8E5C  
then first byte is modified as: byte = (byte | (~0x7F))  
  
after packet is sent:  
chunk of 0x10 bytes from offset 0x2F is copied from request to var16C  
  
## packet 20  
  
packet20: - partially constant  
0x00: 19000000 - response code  
0x04: 00000000 - ?  
0x08: ?? ?? - size of response data (expected 00 53)  
0x0A: ?? - error code (expected 00)  
0x0B: ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? - chunk of 0x50 bytes  
  
byte 0x00 - must be 0x19 - this is some kind of response code that we send in packet19 and expect to be the same in response packet20  
byte 0x04 - must be 0x00 - ?  
byte 0x0A - must be 0x00 - this is some kind of error code  
  
## final validation  
   
After that happens final communication with Kirk  
Since it does not affect transmission of data to SD card anymore  
I assume it is only needed for validation of SD card response   
and termination of initialization if data is invalid  
  
packet that is sent is 0x116 bytes long  
as temp buffer 'generic_buffer' is used  
  
0x00 - 0x20 - data from _00BDCFF8 (from packet6) (from card) - 0x20 bytes  
0x20 - 0x50 - data from _00BDCBC4 (from Kirk service 1C) - 0x30 bytes  
0x50 - 0x70 - data from var15C () - 0x20 bytes  
0x70 - 0xB3 - data from packet18 starting at offset 0x08 - 0x43 bytes  
0xB3 - 0xC3 - data from var16C () - 0x10 bytes  
0xC3 - 0x53 - data from packet20 starting at offset 0x08 - 0x53 bytes  
  
call sub_CAC924(_00BDD018, generic_buffer, KIRK_SERVICE_20, 0x116, packet6_de)  
  
This should call Kirk service 20 for 1000B (xyz wiki "New Vita Kirk 0x20 service. Unknown, but buffer length is 0x116. Related to SceSdif somehow.")  
request size - 0x116  
response size - 0x34  
  
I am not sure if _00BDD018 is used somewhere so I do not know if this a data validation or data generation call  
  
The only other 2 places where _00BDD018 is used are:  
SceSblGcAuthMgrDrmBBForDriver_bb451e83 - this function clears sensitive data from buffers  
SceSblGcAuthMgrDrmBBForDriver_bb70ddc0 - this function copies _00BDD018 buffer to destination  
