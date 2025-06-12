
package com.esotericsoftware.spine;

abstract public class Posed< //
	D extends PosedData<P>, //
	P extends Pose, //
	A extends P> {

	final D data;
	protected final A pose;
	protected final A constrained;
	protected A applied;

	public Posed (D data, A pose, A constrained) {
		if (data == null) throw new IllegalArgumentException("data cannot be null.");
		this.data = data;
		this.pose = pose;
		this.constrained = constrained;
		applied = (A)pose;
	}

	public void setupPose () {
		pose.set(data.setup);
	}

	/** The constraint's setup pose data. */
	public D getData () {
		return data;
	}

	public P getPose () {
		return pose;
	}

	protected A getConstrainedPose () {
		return constrained;
	}

	public A getAppliedPose () {
		return applied;
	}

	/** Resets applied to the pose via Pose.set() **/
	public void reset () {
		applied.set(pose);
	}

	/** applied points at pose **/
	public void poseToApplied () {
		applied = pose;
	}

	public void constrainedToApplied () {
		applied = constrained;
	}

	public String toString () {
		return data.name;
	}
}
