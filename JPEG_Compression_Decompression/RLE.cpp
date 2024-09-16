using namespace std;

vector<pair<int, int>> encoded;

void printEncoded(const vector<pair<int, int>>& encoded) {
    for (const auto& p : encoded) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

void runLengthEncode(const vector<int>& data) {
    
    if (data.empty()) cout<< "0";

    int count = 1;
    int current = data[0];

    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] == current) {
            ++count;
        } else {
            encoded.push_back(make_pair(current, count));
            current = data[i];
            count = 1;
        }
    }
    encoded.push_back(make_pair(current, count)); // Add the last run

}
