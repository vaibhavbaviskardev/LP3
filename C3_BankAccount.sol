// SPDX-License-Identifier: MIT
// C3: Customer bank account - deposit, withdraw, show balance
pragma solidity ^0.8.0;

contract BankAccount {
    mapping(address => uint256) private balance;

    function deposit() public payable {
        require(msg.value > 0, "Send some Ether");
        balance[msg.sender] += msg.value;
    }

    function withdraw(uint256 amount) public {
        require(balance[msg.sender] >= amount, "Insufficient balance");
        balance[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);
    }

    function showBalance() public view returns (uint256) {
        return balance[msg.sender];
    }
}
