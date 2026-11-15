# C2: Create personal wallet in MetaMask & perform transactions

## Steps
1. Install MetaMask extension → *Create a new wallet* → password → back up the 12-word phrase.
2. Account 1 is created; copy its address (0x...).
3. Account icon → *Add account* → create **Account 2** (receiver).
4. Switch to **Sepolia** test network (Settings → Advanced → Show test networks).
5. Fund Account 1 from a Sepolia faucet.
6. Account 1 → *Send* → choose Account 2 → 0.01 ETH → *Next* → *Confirm*.
7. Wait for "Confirmed" in *Activity*; Account 2 balance increases.
8. View it on sepolia.etherscan.io (hash, from, to, value, fee, block no.).

## Viva points
- Wallet stores private keys, not coins; coins live on the blockchain.
- Secret Recovery Phrase regenerates all keys — never share it.
- Public address is derived from the public key; used to receive funds.
- Hot wallet (MetaMask) vs cold wallet (hardware, offline).
