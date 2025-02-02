class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        marks = []
        positive_feedback = set(positive_feedback)
        negative_feedback = set(negative_feedback)

        for i, comment in enumerate(report):
            comments = comment.split()
            score = 0
            for word in comments:
                if word in positive_feedback:
                    score += 3
                if word in negative_feedback:
                    score -= 1
            marks.append((-score, student_id[i]))
        
        heapq.heapify(marks)

        ans = [heapq.heappop(marks)[1] for _ in range(k)]

        return ans
