#include "pci.h"
#include "../util/string.h"
#include "../drivers/screen/simple_screen.h"

extern uint32_t rportl(uint32_t);
extern void wportl(uint16_t, uint32_t);

uint32_t pci_read_long(uint8_t bus, uint8_t device, uint8_t func, uint8_t offset) {
    uint32_t pci_addr = 0x80000000;
    uint32_t l_bus  = (uint32_t)bus;
    uint32_t l_device = (uint32_t)device;
    uint32_t l_func = (uint32_t)func;
    uint32_t result;

    pci_addr |= (l_bus << 16);
    pci_addr |= (l_device << 11);
    pci_addr |= (l_func << 8);
    pci_addr |= (offset & 0xfc);

    wportl(PCI_CONFIG_ADDR, pci_addr);

    result = rportl(PCI_CONFIG_DATA);

    
    char str_result[9];
    long_to_str(result, str_result);
    write_string(str_result);
    newline();

    return result;
}

uint16_t pci_read_short(uint8_t bus, uint8_t device, uint8_t func, uint8_t offset) {
    uint32_t result = pci_read_long(bus, device, func, offset);
    return (result & 0xFFFF0000) >> 16;
}

uint8_t pci_read_byte(uint8_t bus, uint8_t device, uint8_t func, uint8_t offset) {
    uint32_t result = pci_read_long(bus, device, func, offset);
    return (result & 0xFF000000) >> 24;
}

uint8_t pci_enumerate() {
    set_location(0, 6);
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 5; j++) {
            uint16_t result = pci_read_short(i, j, 0, 0);
            pci_read_short(i, j, 0, 2 << 2);
        }
    }
    return 2;
}