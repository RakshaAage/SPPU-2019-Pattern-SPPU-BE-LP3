pragma solidity ^0.4.17;

contract Banking{
    mapping(address=>uint) public userAcc;
    mapping(address=>bool) public userExists;

    function createAcc(uint amount) public returns(string memory)
    {
        require(userExists[msg.sender]==false, "Account already created");
        userAcc[msg.sender]=amount;
        userExists[msg.sender]=true;
        return "Account created successfully";
    }

    function deposit() public payable returns(string memory)
    {
        require(userExists[msg.sender]==true,"Account does not exist");
        require(msg.value>0, "Deposit amount should be greater than zero");
        userAcc[msg.sender]+=msg.value;
        return 'Deposited Successfully';
    }

    function withdraw(uint amount) public payable returns(string memory)
    {
        require(userExists[msg.sender]==true, "Account does not exist");
        require(userAcc[msg.sender]>amount, "Insufficient balance");

        require(amount>0, "Invalid number");
        userAcc[msg.sender]-=amount;
        msg.sender.transfer(amount);
        return "Withdrawn successfully";
    }

    function checkBal() public view returns(uint)
    {
        return userAcc[msg.sender];
    }
}
