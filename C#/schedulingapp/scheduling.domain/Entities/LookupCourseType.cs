using System;
namespace scheduling.domain.Entities
{
    public class LookupCourseType
    {
        public int TypeId { get; set; }
        enum CourseType
        {
            firstBlock,
            secondblock,
            streamLineFirstBlock,
            streamLineSecondBlock,
            streamLine14Weeks,
            virtualLive
        }
    }
}

