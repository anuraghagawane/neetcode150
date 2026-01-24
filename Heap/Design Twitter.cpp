class Twitter {
    int count;
    unordered_map<int, vector<vector<int>>> posts;
    unordered_map<int, unordered_set<int>> followees;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followees[userId].insert(userId);

        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);

        for(auto user: followees[userId]) {
            vector<vector<int>>& userPost = posts[user];
            int n = userPost.size();
            if(n == 0) continue;
            int i = n - 1;
            maxHeap.push({userPost[i][0], i, user});
        }

        vector<int> res;

        while(!maxHeap.empty() && res.size() < 10) {
            auto top = maxHeap.top();
            int c = top[0];
            int i = top[1];
            int user = top[2];
            
            maxHeap.pop();

            vector<vector<int>>& userPost = posts[user];
            res.push_back(userPost[i][1]);

            if(i - 1 < 0) continue;
            i--;
            maxHeap.push({userPost[i][0], i, user});
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */