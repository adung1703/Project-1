#include <bits/stdc++.h>
using namespace std;

inline int time_to_second(string time) {
	return stoi(time.substr(0,2))*3600 + stoi(time.substr(3,2))*60 + stoi(time.substr(6,2));
}

int main(){
	string userid, pid, time, status;
	int point;
	int submissions; // for ?total_number_submissions
	int errors; // for ?number_error_submision
	unordered_map<string, int> errors_of; // for ?number_error_submision_of_user 
	map<pair<string, string>, int> points_in;
	unordered_map<string, int> points_of; // for ?total_point_of_user
	vector<int> submission_before(86400, 0); //for ?number_submission_period
	
	cin >> userid;
	while(userid != "#") {
		cin >> pid >> time >> status >> point;
		submissions += 1;
		if (status == "ERR") {
			errors += 1;
			errors_of[userid] += 1;
		}
		if (point > points_in[{userid, pid}]) points_in[{userid, pid}] = point;
		submission_before[time_to_second(time)] += 1;
		cin >> userid;
	}
	for(pair<pair<string, string>, int> p : points_in){
		points_of[p.first.first] += p.second;
	}
	for(int i = 1; i < 86400; i++) {
		submission_before[i] += submission_before[i-1];
	}
	string query;
	cin >> query;
	while(query != "#") {
		if (query == "?total_number_submissions") cout << submissions << "\n";
		else if (query == "?number_error_submision") cout << errors << "\n";
		else if (query == "?number_error_submision_of_user") {
			string uid;
			cin >> uid;
			cout << errors_of[uid] << "\n";
		}
		else if (query == "?total_point_of_user") {
			string uid;
			cin >> uid;
			cout << points_of[uid] << "\n";			
		}
		else if (query == "?number_submission_period") {
			string from, to;
			cin >> from >> to;
			int second_from = time_to_second(from);
			int second_to = time_to_second(to);
			int totalSubmit = (second_from == 0) ? submission_before[second_to] : (submission_before[second_to] - submission_before[second_from - 1]);
			cout << totalSubmit << '\n';
		}
		cin >> query;
	}
	return 0;
}

