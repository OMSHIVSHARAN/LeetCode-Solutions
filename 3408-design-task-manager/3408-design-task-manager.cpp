class TaskManager {
private:
   unordered_map<int, pair<int, int>> taskDetails;
   set<pair<int, int>> tasksByPriority;
   
public:
   TaskManager(vector<vector<int>>& tasks) {
       for (const auto& task : tasks) {
           add(task[0], task[1], task[2]);
       }
   }
   
   void add(int userId, int taskId, int priority) {
       taskDetails[taskId] = {userId, priority};
       tasksByPriority.insert({-priority, -taskId});
   }
   
   void edit(int taskId, int newPriority) {
       int oldPriority = taskDetails[taskId].second;
       tasksByPriority.erase({-oldPriority, -taskId});
       taskDetails[taskId].second = newPriority;
       tasksByPriority.insert({-newPriority, -taskId});
   }
   
   void rmv(int taskId) {
       int priority = taskDetails[taskId].second;
       tasksByPriority.erase({-priority, -taskId});
       taskDetails.erase(taskId);
   }
   
   int execTop() {
       if (tasksByPriority.empty()) return -1;
       auto topTask = *tasksByPriority.begin();
       int taskId = -topTask.second;
       int userId = taskDetails[taskId].first;
       rmv(taskId);
       return userId;
   }
};
