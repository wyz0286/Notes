//355.设计推特

// 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：

// postTweet(userId, tweetId): 创建一条新的推文
// getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序
// follow(followerId, followeeId): 关注一个用户
// unfollow(followerId, followeeId): 取消关注一个用户

class Twitter {
    struct Node {
        // 哈希表存储关注人的 Id
        unordered_set<int> followee;
        // 用链表存储 tweetId
        list<int> tweet;
    };
    // getNewsFeed 检索的推文的上限以及 tweetId 的时间戳
    int recentMax, time;
    // tweetId 对应发送的时间
    unordered_map<int, int> tweetTime;
    // 每个用户存储的信息
    unordered_map<int, Node> user;
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
        recentMax = 10;
        user.clear();
    }
    void init(int userId) {
        user[userId].followee.clear();
        user[userId].tweet.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (user.find(userId) == user.end()) {
            init(userId);
        }
        // 达到限制，剔除链表末尾元素
        if (user[userId].tweet.size() == recentMax) {
            user[userId].tweet.pop_back();
        }
        user[userId].tweet.push_front(tweetId);
        tweetTime[tweetId] = ++time;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans; ans.clear();
        for (list<int>::iterator it = user[userId].tweet.begin(); it != user[userId].tweet.end(); ++it) {
            ans.emplace_back(*it);
        }
        for (int followeeId : user[userId].followee) {
            if (followeeId == userId) continue; // 可能出现自己关注自己的情况
            vector<int> res; res.clear();
            list<int>::iterator it = user[followeeId].tweet.begin();
            int i = 0;
            // 线性归并
            while (i < (int)ans.size() && it != user[followeeId].tweet.end()) {
                if (tweetTime[(*it)] > tweetTime[ans[i]]) {
                    res.emplace_back(*it);
                    ++it;
                }
                else {
                    res.emplace_back(ans[i]);
                    ++i;
                }
                // 已经找到这两个链表合起来后最近的 recentMax 条推文
                if ((int)res.size() == recentMax) break;
            }
            for (; i < (int)ans.size() && (int)res.size() < recentMax; ++i) res.emplace_back(ans[i]);
            for (; it != user[followeeId].tweet.end() && (int)res.size() < recentMax; ++it) res.emplace_back(*it);
            ans.assign(res.begin(), res.end());
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (user.find(followerId) == user.end()) {
            init(followerId);
        }
        if (user.find(followeeId) == user.end()) {
            init(followeeId);
        }
        user[followerId].followee.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        user[followerId].followee.erase(followeeId);
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