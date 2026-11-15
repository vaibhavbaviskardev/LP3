# C1: Install MetaMask & examine Ether transaction cost

## Steps
1. Chrome → Web Store → search **MetaMask** → *Add to Chrome* → pin the fox icon.
2. *Create a new wallet* → set password → save the 12-word Secret Recovery Phrase → confirm it.
3. Network menu → *Show test networks* ON → select **Sepolia**.
4. Get free test ETH from a Sepolia faucet (paste your account address).
5. *Send* → paste another address → amount 0.001 ETH → on the confirm screen note the **Gas fee**.
6. *Activity* → click the transaction → *View on block explorer* (sepolia.etherscan.io).
7. Note: **Gas Used, Gas Price (Gwei), Base fee, Priority fee, Transaction Fee**.

## Cost formula
Transaction Fee = Gas Used × (Base Fee + Priority Fee)
Example: 21000 × 2 Gwei = 42000 Gwei = 0.000042 ETH
(1 ETH = 10^9 Gwei = 10^18 Wei; a plain ETH transfer always uses 21000 gas)

## Viva points
- Gas = unit of computation; gas price = what you pay per unit.
- Gas limit = max gas you allow; unused gas is refunded.
- Contract calls use more gas than plain transfers.
