package com.CalculatorStrategy;

public class OperationAdd implements Strategy
{

    @Override
    public int doOperation(int firstNum, int secondNum) {
        return firstNum + secondNum;
    }
}
