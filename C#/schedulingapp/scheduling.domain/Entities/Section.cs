using System;
namespace scheduling.domain.Entities
{
    public class Section
    {
        public long SecId { get; set; }
        public long SectionNum { get; set; }
        public virtual Instructor Instructor { get; set; } = default!;
        public virtual TeachingAssistant TeachingAssistant { get; set; } = default!;
        public long InstructorId { get; set; }
        public long TaId { get; set; }
    }
}

