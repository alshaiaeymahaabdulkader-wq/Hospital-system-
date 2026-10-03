#include <iostream>
using namespace std;

int main() {

    const int SIZE = 10;

    // ================= PATIENT DATA =================
    int p_id[SIZE];
    char p_name[SIZE][20];
    int p_dept[SIZE];
    double p_info[SIZE][4];
    int count = 0;

    // ================= DOCTOR DATA =================
    int d_id[SIZE];
    char d_name[SIZE][20];
    int d_dept[SIZE];
    int d_hours[SIZE];
    int d_count = 0;

    // ================= APPOINTMENT DATA =================
    int app_p_id[SIZE];
    int app_d_id[SIZE];
    int app_dept[SIZE];
    double app_time[SIZE];
    int app_count = 0;

    int op;

    do {

        cout << "\n=====================================" << endl;
        cout << "     HOSPITAL MANAGEMENT SYSTEM     " << endl;
        cout << "=====================================" << endl;
        cout << "1. Patient Management" << endl;
        cout << "2. Doctor Management" << endl;
        cout << "3. Appointments" << endl;
        cout << "4. Medical Departments" << endl;
        cout << "5. Hospital Statistics" << endl;
        cout << "6. Search" << endl;
        cout << "7. Reports" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> op;

        switch (op) {

        // ==================================================
        // 1. PATIENT MANAGEMENT
        // ==================================================
        case 1: {

            int sub_op;

            cout << "\n--- Patient Management ---" << endl;
            cout << "1. Add Patient" << endl;
            cout << "2. View All Patients" << endl;
            cout << "3. Search Patient" << endl;
            cout << "Enter choice: ";
            cin >> sub_op;

            if (sub_op == 1) {

                if (count < SIZE) {

                    cout << "\nEnter Patient ID: ";
                    cin >> p_id[count];

                    cout << "Enter Patient Name: ";
                    cin >> p_name[count];

                    cout << "Enter Department (1-Emergency, 2-Internal, 3-Pediatrics, 4-Surgery, 5-Dental): ";
                    cin >> p_dept[count];

                    while (p_dept[count] < 1 || p_dept[count] > 5) {
                        cout << "Invalid department! Re-enter (1 to 5): ";
                        cin >> p_dept[count];
                    }

                    cout << "Enter Age: ";
                    cin >> p_info[count][0];

                    cout << "Enter Temperature: ";
                    cin >> p_info[count][1];

                    cout << "Enter Blood Pressure: ";
                    cin >> p_info[count][2];

                    cout << "Enter Pulse: ";
                    cin >> p_info[count][3];

                    double temp = p_info[count][1];

                    cout << "Patient Status: ";

                    if (temp >= 39.0) {

                        cout << "Emergency" << endl;

                        // Nested if
                        if (p_info[count][3] > 100) {
                            cout << "Warning: High pulse!" << endl;
                        }

                    }
                    else if (temp >= 37.5) {
                        cout << "Needs Attention" << endl;
                    }
                    else {
                        cout << "Normal" << endl;
                    }

                    count++;

                    cout << "--> Patient added successfully!" << endl;
                }
                else {
                    cout << "Error: Patient list is full!" << endl;
                }
            }

            else if (sub_op == 2) {

                if (count == 0) {

                    cout << "No patients registered yet." << endl;

                }
                else {

                    cout << "\n--- All Patients Data ---" << endl;

                    for (int i = 0; i < count; i++) {

                        cout << "\nID: " << p_id[i]
                             << " | Name: " << p_name[i]
                             << " | Dept: " << p_dept[i] << endl;

                        cout << "Details -> ";

                        for (int j = 0; j < 4; j++) {

                            if (j == 0)
                                cout << "Age: " << p_info[i][j] << " | ";

                            else if (j == 1)
                                cout << "Temp: " << p_info[i][j] << " | ";

                            else if (j == 2)
                                cout << "BP: " << p_info[i][j] << " | ";

                            else
                                cout << "Pulse: " << p_info[i][j];
                        }

                        cout << endl;
                    }
                }
            }

            else if (sub_op == 3) {

                int search_id;
                bool found = false;

                cout << "Enter Patient ID: ";
                cin >> search_id;

                for (int i = 0; i < count; i++) {

                    if (p_id[i] == search_id) {

                        cout << "\nPatient Found!" << endl;
                        cout << "ID: " << p_id[i] << endl;
                        cout << "Name: " << p_name[i] << endl;
                        cout << "Department: " << p_dept[i] << endl;
                        cout << "Age: " << p_info[i][0] << endl;
                        cout << "Temperature: " << p_info[i][1] << endl;
                        cout << "Blood Pressure: " << p_info[i][2] << endl;
                        cout << "Pulse: " << p_info[i][3] << endl;

                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Patient not found!" << endl;
            }

            else {
                cout << "Invalid choice!" << endl;
            }

            break;
        }

        // ==================================================
        // 2. DOCTOR MANAGEMENT
        // ==================================================
        case 2: {

            int sub_op;

            cout << "\n--- Doctor Management ---" << endl;
            cout << "1. Add Doctor" << endl;
            cout << "2. View All Doctors" << endl;
            cout << "3. Search Doctor" << endl;
            cout << "4. Doctors By Department" << endl;
            cout << "Enter choice: ";
            cin >> sub_op;

            if (sub_op == 1) {

                if (d_count < SIZE) {

                    cout << "\nEnter Doctor ID: ";
                    cin >> d_id[d_count];

                    cout << "Enter Doctor Name: ";
                    cin >> d_name[d_count];

                    cout << "Enter Department (1 to 5): ";
                    cin >> d_dept[d_count];

                    while (d_dept[d_count] < 1 || d_dept[d_count] > 5) {
                        cout << "Invalid department! Re-enter (1 to 5): ";
                        cin >> d_dept[d_count];
                    }

                    cout << "Enter Working Hours: ";
                    cin >> d_hours[d_count];

                    d_count++;

                    cout << "--> Doctor added successfully!" << endl;
                }
                else {
                    cout << "Error: Doctor list is full!" << endl;
                }
            }

            else if (sub_op == 2) {

                if (d_count == 0) {

                    cout << "No doctors registered yet." << endl;

                }
                else {

                    cout << "\n--- All Doctors Data ---" << endl;

                    for (int i = 0; i < d_count; i++) {

                        cout << "ID: " << d_id[i]
                             << " | Name: " << d_name[i]
                             << " | Dept: " << d_dept[i]
                             << " | Hours: " << d_hours[i]
                             << " hrs" << endl;
                    }
                }
            }

            else if (sub_op == 3) {

                int search_id;
                bool found = false;

                cout << "Enter Doctor ID: ";
                cin >> search_id;

                for (int i = 0; i < d_count; i++) {

                    if (d_id[i] == search_id) {

                        cout << "\nDoctor Found!" << endl;
                        cout << "ID: " << d_id[i] << endl;
                        cout << "Name: " << d_name[i] << endl;
                        cout << "Department: " << d_dept[i] << endl;
                        cout << "Working Hours: " << d_hours[i] << endl;

                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Doctor not found!" << endl;
            }

            else if (sub_op == 4) {

                int dept;
                bool found = false;

                cout << "Enter Department Number: ";
                cin >> dept;

                while (dept < 1 || dept > 5) {
                    cout << "Invalid department! Re-enter (1 to 5): ";
                    cin >> dept;
                }

                for (int i = 0; i < d_count; i++) {

                    if (d_dept[i] == dept) {

                        cout << "Doctor ID: " << d_id[i]
                             << " | Name: " << d_name[i] << endl;

                        found = true;
                    }
                }

                if (!found)
                    cout << "No doctors found in this department." << endl;
            }

            else {
                cout << "Invalid choice!" << endl;
            }

            break;
        }

        // ==================================================
        // 3. APPOINTMENTS
        // ==================================================
        case 3: {

            int sub_op;

            cout << "\n--- Appointments ---" << endl;
            cout << "1. Add Appointment" << endl;
            cout << "2. View All Appointments" << endl;
            cout << "3. Search Appointment" << endl;
            cout << "Enter choice: ";
            cin >> sub_op;

            if (sub_op == 1) {

                if (app_count < SIZE) {

                    int patientID;
                    int doctorID;
                    bool patientFound = false;
                    bool doctorFound = false;

                    cout << "\nEnter Patient ID: ";
                    cin >> patientID;

                    for (int i = 0; i < count; i++) {

                        if (p_id[i] == patientID) {
                            patientFound = true;
                            break;
                        }
                    }

                    if (!patientFound) {

                        cout << "Patient does not exist!" << endl;

                    }
                    else {

                        cout << "Enter Doctor ID: ";
                        cin >> doctorID;

                        for (int i = 0; i < d_count; i++) {

                            if (d_id[i] == doctorID) {
                                doctorFound = true;
                                break;
                            }
                        }

                        if (!doctorFound) {

                            cout << "Doctor does not exist!" << endl;

                        }
                        else {

                            cout << "Enter Department (1 to 5): ";
                            cin >> app_dept[app_count];
