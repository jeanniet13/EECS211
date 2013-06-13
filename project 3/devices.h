using namespace std;

class malfunctionRecord {
	public:
		malfunctionRecord();
		void malfunction(int mlfn, int tm);
		void display();
		int malfunctionRecord::getRecord(int *m, int *t);
	private:
		int malfunctionCount;
		int lastmalfunctionType;
		int lastmalfunctionTime;
	}
	
class device {
	public:
		device(char *n, int sn);
		~device;
		void display();
		void recordMalfunction(int m, int t);
		int getRecord(int *m, int *t);
		int amIThisDevice(char *n);
	private:
		char* name;
		int serialnumber;
		int value;
		malfunctionRecord name;
		
		
	}