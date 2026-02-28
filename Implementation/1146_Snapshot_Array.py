class SnapshotArray:

    def __init__(self, length: int):
        # Initialize the list of list of tuples to hold our data
        # [ [ (snap_id, val),(snap_id, val) ], [ (snap_id, val) ] ]
        self.data = [[(0,0)] for _ in range(length)]
        self.snap_id = 0

    def set(self, index: int, val: int) -> None:
	# Check if we have a snapshot for current snap_id
	if self.data[index][-1][0] == self.snap_id:
		self.data[index][-1] = (self.snap_id, val)
	# If not, that means a snapshot was taken in the past but this is a new value
	# so we append it to our index list
	else:
		self.data[index].append((self.snap_id, val))

    def snap(self) -> int:
	# Simply increment the current id and return the now old id
        self.snap_id += 1
        return self.snap_id - 1
   
    def get(self, index: int, snap_id: int) -> int:
	# We know the index we want from the parameter
	# This helps in isolating it
	target = self.data[index]
	
	# Now, we do a binary search to find the exact snapshot id or the closest one to it
	ans = bisect_right(target, (snap_id, float('inf'))) - 1
        return target[ans][1]
