package com.CalculatorStrategy;

public class OperationSubstract implements Strategy
{
    @Override
    public int doOperation(int firstNum, int secondNum) {
        return firstNum - secondNum;
    }
}
