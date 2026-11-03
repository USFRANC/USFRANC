#ifndef BITCOIN_CHAINPARAMSSEEDS_H
#define BITCOIN_CHAINPARAMSSEEDS_H
/**
 * List of fixed seed nodes for the USFranc network
 *
 * Each line contains a BIP155 serialized (networkID, addr, port) tuple.
 * 85.25.172.140:19777 and 62.138.16.67:19777
 */
static const uint8_t chainparams_seed_main[] = {
    0x01,0x04,0x55,0x19,0xac,0x8c,0x4d,0x41,
    0x01,0x04,0x3e,0x8a,0x10,0x43,0x4d,0x41,
};

static const uint8_t chainparams_seed_test[] = {
    0x01,0x04,0x55,0x19,0xac,0x8c,0x4d,0x42,
};
#endif // BITCOIN_CHAINPARAMSSEEDS_H
