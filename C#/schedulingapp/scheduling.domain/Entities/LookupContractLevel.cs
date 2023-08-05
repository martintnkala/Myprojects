using System;
namespace scheduling.domain.Entities
{
    public class LookupContractLevel
    {
        public int ContractLevelId { get; set; }
        enum ContractLevel
        {
            green = 1,
            yellow = 2,
            red = 3
        }
    }
}

