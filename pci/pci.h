#ifndef PCI_H
#define PCI_H

#include "inttypes.h"

#define PCI_CONFIG_ADDR 0xCF8
#define PCI_CONFIG_DATA 0xCFC

uint8_t pci_read_byte(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset);
uint16_t pci_read_short(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset);
uint32_t pci_read_long(uint8_t bus, uint8_t device, uint8_t func, uint8_t offset);
uint8_t pci_enumerate();

#endif // PCI_H