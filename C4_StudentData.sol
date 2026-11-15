// SPDX-License-Identifier: MIT
// C4: Student data using struct, array and fallback function
pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        uint256 roll;
        string name;
        uint256 marks;
    }

    Student[] public students;
    event Received(address from, uint256 amount);

    function addStudent(
        uint256 roll,
        string memory name,
        uint256 marks
    ) public {
        students.push(Student({roll: roll, name: name, marks: marks}));
    }

    function getStudent(
        uint256 index
    ) public view returns (uint256, string memory, uint256) {
        Student memory student = students[index];
        return (student.roll, student.name, student.marks);
    }

    function count() public view returns (uint256) {
        return students.length;
    }

    fallback() external payable {
        emit Received(msg.sender, msg.value);
    }

    receive() external payable {
        emit Received(msg.sender, msg.value);
    }
}
