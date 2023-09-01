using System;
namespace scheduling.domain.Entities
{
    public class TeachingAssistant : LookupContractLevel
    {
        public long TaId { get; set; }
        public int INumber { get; set; }
        public string FullName { get; set; } = string.Empty;
        public int PhoneNumber { get; set; }
        public string EmailAddress { get; set; } = string.Empty;
    }
}

