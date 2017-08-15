#include "controller.h"

void Leap_Listener::onConnect(const Controller& controller) {
	std::cout << "Connected" << std::endl;
	// Enable gestures, set Config values:
	controller.enableGesture(Gesture::TYPE_SWIPE);
	controller.config().setFloat("Gesture.Swipe.MinLength", 200.0);
	controller.config().save();
}
//Not dispatched when running in a debugger
void Leap_Listener::onDisconnect(const Controller& controller) {
	std::cout << "Disconnected" << std::endl;
}
void Leap_Listener::onFrame(const Controller& controller) {
	// std::cout << "New frame available" << std::endl;
	Frame frame = controller.frame();
	// Process this frame's data...
}

void ex() {
	Controller controller;
	Leap_Listener listener;
	controller.addListener(listener);
	Frame frame = controller.frame();
	HandList hands = frame.hands();
	PointableList pointables = frame.pointables();
	FingerList fingers = frame.fingers();
	ToolList tools = frame.tools();
	Finger finger;
	Vector curPosition;
	Finger::Type fingertype = finger.type();
	while (1) {
		const Frame frame = controller.frame();
		/*
		std::cout << "Frame id: " << frame.id()
			<< ", timestamp: " << frame.timestamp()
			<< ", hands: " << frame.hands().count()
			<< ", fingers: " << frame.fingers().count()
			<< ", finger type:  " << fingertype;
		std::cout << curPosition << std::endl;
		*/
		FingerList phalanges1 = frame.hands()[0].fingers();
		FingerList phalanges2 = frame.hands()[1].fingers();
		int fingers = 10;
		int basis = 3;
		float **fingerPos = new float*[fingers];
		for (int i = 0; i < fingers; i++) {
			fingerPos[i] = new float[basis];
		}
		int count = 0;
		for (FingerList::const_iterator fl = phalanges1.begin(); fl != phalanges1.end(); fl++) {
			float dist = (*fl).touchDistance();
			Vector curPos = (*fl).tipPosition();
			fingerPos[count][0] = curPos[0];
			fingerPos[count][1] = curPos[1];
			fingerPos[count][2] = curPos[2];
			std::cout << "Distance of finger from touch display = " << dist 
				<< "\n" << "Finger Id = " << (*fl) 
				<< "\n"<< "position of Finger = " << curPos << std::endl;
			count += 1;
		}
		std::cout << "-------------------------------------------------------------------------------" << std::endl;
		for (FingerList::const_iterator fl = phalanges2.begin(); fl != phalanges2.end(); fl++) {
			std::cout << *fl << std::endl;
			float dist = (*fl).touchDistance();
			Vector curPos = (*fl).tipPosition();
			fingerPos[count][0] = curPos[0];
			fingerPos[count][1] = curPos[1];
			fingerPos[count][2] = curPos[2];
			std::cout << "Distance of finger from touch display = " << dist 
				<< "\n" << "Finger Id = " << (*fl) 
				<< "\n" << "position of Finger = " << curPos << std::endl;
			count += 1;
		}
		std::cout << "-------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << "[ " << fingerPos[i][0] << ", " << fingerPos[i][1] << ", " << fingerPos[i][2] << " ]" << std::endl;
		}
	}
} 