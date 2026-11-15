# How to deploy C3 / C4 (Remix IDE)

1. Open remix.ethereum.org → new file → paste the .sol code.
2. *Solidity Compiler* tab → version 0.8.x → **Compile**.
3. *Deploy & Run* tab → Environment:
   - **Remix VM** (local test), or
   - **Injected Provider - MetaMask** (Sepolia) for "deploy on a test network".
4. Click **Deploy** → confirm in MetaMask.

## C3 test
- Put 1 ether in the VALUE box → click `deposit`.
- `showBalance` → balance in Wei.
- `withdraw(500000000000000000)` → withdraws 0.5 ETH.

## C4 test
- `addStudent(1, "Amit", 85)` → `getStudent(0)` → `count`.
- Fallback: put a value in VALUE, click *Transact* under "Low level interactions" → `Received` event logged.
- Gas & fees: expand the transaction in the Remix console → **gas**, **transaction cost**, **execution cost**.
  Transaction cost = total gas of the tx; execution cost = gas for running the code only.
