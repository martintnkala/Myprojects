import React, { useState, useEffect } from "react";

export const StudentManagement = () => {

  const [student, setStudent] = useState({
    firstName: "Usher",
    lastName: "Johns",
    emailAddress: "usher@example.com",
  });

  function updateStudent() {
    setStudent({
      firstName: "Martin",
      lastName: "Nkala",
      emailAddress: "martin@example.com",
    });
  }

  function handleClickUpdate(){
    if (!student.firstName) {
        updateStudent();
      }
  }

//   useEffect(() => {
//     if (!student.firstName) {
//       updateStudent();
//     }
//   }, [student.firstName]);

  return (
    <div>
      <h1>Student Details</h1>
      <p>First Name: {student.firstName}</p>
      <p>Last Name: {student.lastName}</p>
      <p>Email Address: {student.emailAddress}</p>


      <button onClick={handleClickUpdate}>Update Student Details</button>
    </div>
  );
};
