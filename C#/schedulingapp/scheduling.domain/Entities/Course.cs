using System;
namespace scheduling.domain.Entities
{
    public class Course : LookupCourseType
    {
        public long CourseId { get; set; }
        public long CourseCode { get; set; }
        public string Title { get; set; } = string.Empty;

    }
}

