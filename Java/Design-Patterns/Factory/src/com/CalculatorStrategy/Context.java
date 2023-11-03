package com.CalculatorStrategy;

public class Context
{
    private Strategy strategy;

    public Context(Strategy strategy) //
    {
        this.strategy = strategy;
    }

    public int execStrategy(int firstNum, int secondNum)
    {
        return strategy.doOperation(firstNum, secondNum);
    }
}
