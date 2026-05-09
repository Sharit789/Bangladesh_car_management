
// ============================================================
//        CAR MANAGEMENT SYSTEM - Bangladesh Style
//        Complete C++ Program using struct & vector
// ============================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// ============================================================
//                    CAR STRUCT DEFINITION
// ============================================================
struct Car {
    // Owner & Car Identity
    string ownerName;
    string carModel;
    double carPrice;
    double registrationCost;
    double insuranceCost;
    double fuelCostPerMonth;
    double maintenanceCost;

    // Technical Info
    int    mileage;
    string chassisNumber;
    string engineNumber;
    string fitnessCertificateNumber;
    int    importYear;

    // Document Status
    bool registrationPaperAvailable;
    bool taxTokenAvailable;
    bool insurancePaperAvailable;

    // Condition Reports
    string ACCondition;
    string brakeCondition;
    string steeringCondition;
    string tireCondition;
    string batteryCondition;

    // History & Risk
    bool   accidentHistory;
    bool   floodDamage;
    string serviceHistory;
    double resaleValue;

    // Additional Checks
    bool   sparePartsAvailable;
    string smokeCondition;
    bool   oilLeakage;
    string rustCondition;
};

// ============================================================
//                    HELPER FUNCTIONS
// ============================================================

// Pad/truncate a string to a fixed width for table alignment
string fitStr(const string& s, int width) {
    if ((int)s.size() >= width) return s.substr(0, width);
    return s + string(width - s.size(), ' ');
}

string boolToYesNo(bool v) { return v ? "Yes" : "No"; }

// Generate a Bangladesh-style chassis number
// Format: BD-XXXX-YYYYYYY  (prefix + 4-digit group + 7-digit serial)
string makeChassis(int index) {
    string prefixes[] = {"BD", "JPN", "KOR", "CHN", "IND"};
    string mid[] = {"PRMO","AXIO","GRCE","XTRA","ALIO","VITZ","CIVI","CORS","SWIFT","ATOZ"};
    ostringstream oss;
    oss << prefixes[index % 5] << "-"
        << mid[index % 10] << "-"
        << setw(7) << setfill('0') << (1000000 + index * 137 % 9000000);
    return oss.str();
}

// Generate engine number
string makeEngine(int index) {
    string codes[] = {"2NZ-","1NZ-","2AZ-","1AZ-","LEA-","MR20-","K12B-","D13B-","G13A-","ZC-"};
    ostringstream oss;
    oss << codes[index % 10]
        << setw(6) << setfill('0') << (500000 + index * 251 % 499999);
    return oss.str();
}

// Generate Bangladesh fitness certificate number
// Format: BRTA/DHAKA/YYYY/NNNNNN
string makeFitnessCert(int index) {
    string offices[] = {"DHAKA","CTGM","SYLHET","RAJSHAHI","KHULNA","BARISAL","RANGPUR","MYMENSINGH"};
    int year = 2018 + (index % 6);
    ostringstream oss;
    oss << "BRTA/" << offices[index % 8] << "/" << year << "/"
        << setw(6) << setfill('0') << (100000 + index * 313 % 899999);
    return oss.str();
}

// ============================================================
//   DATA TABLES (Bangladesh-realistic)
// ============================================================

const string OWNER_NAMES[] = {
    "Md. Rahim Uddin","Karim Hossain","Farida Begum","Shahidul Islam",
    "Nasrin Akter","Abdul Mannan","Roksana Khanom","Mizanur Rahman",
    "Shirin Akter","Babul Chandra Das","Nurul Islam","Taslima Khatun",
    "Jasim Uddin","Rehana Parvin","Mokhlesur Rahman","Halima Begum",
    "Anwar Hossain","Kohinoor Begum","Selim Reza","Mofizur Rahman",
    "Amena Khatun","Zakir Hossain","Dilara Begum","Shahjahan Mia",
    "Fatema Akter","Alamgir Hossain","Nargis Sultana","Shafiqul Islam",
    "Morjina Begum","Rezaul Karim","Sumaiya Akter","Khorshed Alam",
    "Bilkis Begum","Nazrul Islam","Champa Rani","Golam Mostafa",
    "Farhana Akter","Moniruzzaman","Lovely Akter","Sirajul Islam",
    "Masudul Haque","Rahela Khatun","Belal Hossain","Sabina Yesmin",
    "Mahbubur Rahman","Parveen Akter","Abdur Razzak","Momtaz Begum",
    "Lutfur Rahman","Hasina Begum"
};
const int OWNER_COUNT = 50;

const string CAR_MODELS[] = {
    "Toyota Premio","Toyota Axio","Honda Grace","Nissan X-Trail",
    "Toyota Allion","Toyota Vitz","Honda Civic","Toyota Corolla",
    "Suzuki Swift","Hyundai i10","Mitsubishi Lancer","Toyota Noah",
    "Honda Fit","Nissan Sunny","Toyota IST","Honda Freed",
    "Suzuki Alto","Toyota Rush","Nissan Note","Toyota Fielder"
};
const int MODEL_COUNT = 20;

const string CONDITIONS[] = {"Excellent","Good","Average","Fair","Poor"};
const string SMOKE_COND[]  = {"None","Light","Moderate","Heavy"};
const string RUST_COND[]   = {"None","Minor","Moderate","Severe"};
const string SVC_HIST[]    = {
    "Full service history available",
    "Partial service records",
    "Dealer maintained",
    "Owner maintained - no records",
    "Recently serviced at workshop",
    "Service book present"
};

// ============================================================
//                    POPULATE CARS
// ============================================================
void populateCars(vector<Car>& cars) {
    // Base prices in BDT for each model (approx)
    double basePrices[MODEL_COUNT] = {
        1800000, 1450000, 1600000, 2800000, 1750000,
         950000, 2200000, 1650000,  950000,  750000,
        1200000, 2400000, 1100000,  900000, 1050000,
        1300000,  650000, 2100000,  980000, 1380000
    };

    int importYears[] = {2008,2009,2010,2011,2012,2013,2014,2015,2016,2017,2018};

    for (int i = 0; i < 300; i++) {
        Car& c = cars[i];

        int modelIdx   = i % MODEL_COUNT;
        int ownerIdx   = i % OWNER_COUNT;
        int yearIdx    = i % 11;

        // Identity
        c.ownerName  = OWNER_NAMES[ownerIdx];
        c.carModel   = CAR_MODELS[modelIdx];
        c.importYear = importYears[yearIdx];

        // Pricing (slight random-feel via index arithmetic)
        double priceVariation = 1.0 - (i % 10) * 0.02;          // -0% to -18%
        c.carPrice          = basePrices[modelIdx] * priceVariation;
        c.registrationCost  = c.carPrice * 0.025;
        c.insuranceCost     = c.carPrice * 0.018;
        c.fuelCostPerMonth  = 5000 + (i % 15) * 500;             // 5000–12000 BDT
        c.maintenanceCost   = 3000 + (i % 12) * 400;             // 3000–7400 BDT

        // Mileage: older car = more km; vary by model popularity
        int ageFactor = (2024 - c.importYear);
        c.mileage = 20000 + ageFactor * 8000 + (i % 7) * 3000;  // 28k–160k km

        // Numbers
        c.chassisNumber           = makeChassis(i);
        c.engineNumber            = makeEngine(i);
        c.fitnessCertificateNumber= makeFitnessCert(i);

        // Documents: most cars have papers; a few don't
        c.registrationPaperAvailable = (i % 9 != 0);
        c.taxTokenAvailable          = (i % 11 != 0);
        c.insurancePaperAvailable    = (i % 13 != 0);

        // Conditions improve for newer / lower-index cars
        int condIdx = (i / 60);          // 0..4 as i goes 0..299
        c.ACCondition       = CONDITIONS[min(condIdx,     4)];
        c.brakeCondition    = CONDITIONS[min(condIdx,     4)];
        c.steeringCondition = CONDITIONS[min((condIdx+1)/2, 4)];
        c.tireCondition     = CONDITIONS[min(condIdx,     4)];
        c.batteryCondition  = CONDITIONS[min((condIdx+1)/2, 4)];

        // History
        c.accidentHistory   = (i % 7 == 0);
        c.floodDamage       = (i % 17 == 0);
        c.serviceHistory    = SVC_HIST[i % 6];
        c.resaleValue       = c.carPrice * (0.55 + (5 - condIdx) * 0.05);

        // Extra checks
        c.sparePartsAvailable = (modelIdx < 12);      // common models have spares
        c.smokeCondition      = SMOKE_COND[min(condIdx, 3)];
        c.oilLeakage          = (i % 19 == 0);
        c.rustCondition       = RUST_COND[min(condIdx, 3)];
    }
}

// ============================================================
//                   DISPLAY FUNCTIONS
// ============================================================

void printDivider(char ch = '-', int len = 130) {
    cout << string(len, ch) << "\n";
}

void printHeader() {
    printDivider('=');
    cout << "  CAR MANAGEMENT SYSTEM  |  Bangladesh  |  Total Cars: 300\n";
    printDivider('=');
    // Column headers
    cout << left
         << setw(4)  << "No."
         << setw(22) << "Owner Name"
         << setw(17) << "Car Model"
         << setw(12) << "Price(BDT)"
         << setw(9)  << "Mileage"
         << setw(6)  << "Year"
         << setw(8)  << "AC"
         << setw(8)  << "Brake"
         << setw(9)  << "Tire"
         << setw(8)  << "Smoke"
         << setw(10) << "Rust"
         << setw(6)  << "Accdt"
         << setw(6)  << "Flood"
         << setw(12) << "Resale(BDT)"
         << "\n";
    printDivider('-');
}

void printCarBrief(int no, const Car& c) {
    cout << left
         << setw(4)  << no
         << setw(22) << fitStr(c.ownerName, 21)
         << setw(17) << fitStr(c.carModel,  16)
         << setw(12) << fixed << setprecision(0) << c.carPrice
         << setw(9)  << c.mileage
         << setw(6)  << c.importYear
         << setw(8)  << fitStr(c.ACCondition,    7)
         << setw(8)  << fitStr(c.brakeCondition,  7)
         << setw(9)  << fitStr(c.tireCondition,   8)
         << setw(8)  << fitStr(c.smokeCondition,  7)
         << setw(10) << fitStr(c.rustCondition,   9)
         << setw(6)  << boolToYesNo(c.accidentHistory)
         << setw(6)  << boolToYesNo(c.floodDamage)
         << setw(12) << c.resaleValue
         << "\n";
}

void printCarDetailed(int no, const Car& c) {
    printDivider('=');
    cout << "  CAR #" << no << "\n";
    printDivider('-');

    // Row 1 – Identity
    cout << left
         << "  Owner        : " << c.ownerName      << "\n"
         << "  Model        : " << c.carModel        << "\n"
         << "  Import Year  : " << c.importYear      << "\n";

    // Row 2 – Numbers
    cout << "  Chassis No.  : " << c.chassisNumber           << "\n"
         << "  Engine No.   : " << c.engineNumber            << "\n"
         << "  Fitness Cert : " << c.fitnessCertificateNumber<< "\n";

    // Row 3 – Financials
    cout << fixed << setprecision(0)
         << "  Car Price    : BDT " << setw(10) << c.carPrice
         << "   Registration: BDT " << setw(8)  << c.registrationCost  << "\n"
         << "  Insurance    : BDT " << setw(10) << c.insuranceCost
         << "   Fuel/Month  : BDT " << setw(8)  << c.fuelCostPerMonth  << "\n"
         << "  Maintenance  : BDT " << setw(10) << c.maintenanceCost
         << "   Resale Value: BDT " << setw(8)  << c.resaleValue       << "\n";

    // Row 4 – Mileage & Docs
    cout << "  Mileage      : " << c.mileage << " km\n"
         << "  Reg. Paper   : " << boolToYesNo(c.registrationPaperAvailable)
         << "   Tax Token   : " << boolToYesNo(c.taxTokenAvailable)
         << "   Insurance   : " << boolToYesNo(c.insurancePaperAvailable) << "\n";

    // Row 5 – Conditions
    cout << "  AC           : " << setw(10) << c.ACCondition
         << "  Brake        : " << setw(10) << c.brakeCondition
         << "  Steering     : " << c.steeringCondition        << "\n"
         << "  Tire         : " << setw(10) << c.tireCondition
         << "  Battery      : " << setw(10) << c.batteryCondition
         << "  Smoke        : " << c.smokeCondition           << "\n"
         << "  Rust         : " << setw(10) << c.rustCondition
         << "  Oil Leakage  : " << boolToYesNo(c.oilLeakage)  << "\n";

    // Row 6 – History
    cout << "  Accident Hist: " << boolToYesNo(c.accidentHistory)
         << "   Flood Damage: " << boolToYesNo(c.floodDamage)
         << "   Spare Parts : " << boolToYesNo(c.sparePartsAvailable) << "\n"
         << "  Service Hist : " << c.serviceHistory << "\n";
}

// ============================================================
//                    SUMMARY STATISTICS
// ============================================================
void printSummary(const vector<Car>& cars) {
    double totalValue = 0, totalResale = 0;
    int accidents = 0, floods = 0, oilLeaks = 0;
    int condCounts[5] = {0,0,0,0,0};  // Excellent..Poor

    for (const Car& c : cars) {
        totalValue  += c.carPrice;
        totalResale += c.resaleValue;
        if (c.accidentHistory) accidents++;
        if (c.floodDamage)     floods++;
        if (c.oilLeakage)      oilLeaks++;
        for (int k = 0; k < 5; k++)
            if (c.ACCondition == CONDITIONS[k]) condCounts[k]++;
    }

    printDivider('=');
    cout << "  SUMMARY STATISTICS\n";
    printDivider('-');
    cout << fixed << setprecision(0)
         << "  Total Cars         : " << cars.size()             << "\n"
         << "  Total Fleet Value  : BDT " << totalValue          << "\n"
         << "  Total Resale Value : BDT " << totalResale         << "\n"
         << "  Cars w/ Accident   : " << accidents               << "\n"
         << "  Cars w/ Flood Dmg  : " << floods                  << "\n"
         << "  Cars w/ Oil Leak   : " << oilLeaks                << "\n";
    cout << "\n  AC Condition Breakdown:\n";
    for (int k = 0; k < 5; k++)
        cout << "    " << setw(10) << left << CONDITIONS[k]
             << ": " << condCounts[k] << " cars\n";
    printDivider('=');
}

// ============================================================
//                    SEARCH FUNCTION
// ============================================================
void searchByModel(const vector<Car>& cars, const string& model) {
    printDivider('=');
    cout << "  SEARCH RESULTS for model: \"" << model << "\"\n";
    printDivider('-');
    int found = 0;
    for (int i = 0; i < (int)cars.size(); i++) {
        if (cars[i].carModel == model) {
            cout << "  Car #" << (i+1) << " | Owner: " << cars[i].ownerName
                 << " | Price: BDT " << fixed << setprecision(0) << cars[i].carPrice
                 << " | Mileage: " << cars[i].mileage << " km"
                 << " | Year: " << cars[i].importYear << "\n";
            found++;
        }
    }
    if (!found) cout << "  No cars found for that model.\n";
    printDivider('-');
    cout << "  Found: " << found << " car(s)\n";
    printDivider('=');
}

// ============================================================
//                         MAIN
// ============================================================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. Create vector of 300 cars
    vector<Car> cars(300);

    // 2. Populate with Bangladesh-style data
    populateCars(cars);

    // --------------------------------------------------------
    // 3. Display: Full Detailed View for first 5 cars
    // --------------------------------------------------------
    cout << "\n";
    printDivider('*');
    cout << "  DETAILED VIEW  (Cars 1 - 5)\n";
    printDivider('*');
    for (int i = 0; i < 5; i++)
        printCarDetailed(i + 1, cars[i]);
    printDivider('=');

    // --------------------------------------------------------
    // 4. Display: Summary table for ALL 300 cars
    // --------------------------------------------------------
    cout << "\n\n";
    printDivider('*');
    cout << "  FULL CAR LIST  (All 300 Cars)\n";
    printDivider('*');
    printHeader();
    for (int i = 0; i < 300; i++)
        printCarBrief(i + 1, cars[i]);
    printDivider('=');

    // --------------------------------------------------------
    // 5. Summary Statistics
    // --------------------------------------------------------
    cout << "\n";
    printSummary(cars);

    // --------------------------------------------------------
    // 6. Sample Search
    // --------------------------------------------------------
    cout << "\n";
    searchByModel(cars, "Toyota Premio");
    searchByModel(cars, "Nissan X-Trail");

    cout << "\n  Program completed successfully.\n\n";
    return 0;
}
