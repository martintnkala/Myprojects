using System;
namespace scheduling.domain.Entities
{
    public class Instructor
    {
        public int Id { get; set; }
        public string FullName { get; set; } = string.Empty;
        public int PhoneNumber { get; set; }
        public string EmailAddress { get; set; } = string.Empty;
    }
}

