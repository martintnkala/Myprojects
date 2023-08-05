using System;
namespace scheduling.domain.Entities
{
    public class Course : LookupCourseType
    {
        public int CourseId { get; set; }
        public string Title { get; set; } = string.Empty;

    }
}

