import 'package:flutter/material.dart';

void main() {
  runApp(const Myapp());
}

class Myapp extends StatelessWidget {
  const Myapp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      home: Home(),
    );
  }
}

class Home extends StatefulWidget {
  const Home({super.key});

  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text(
            "Hello User!",
            style: TextStyle(color: Colors.white),
          ),
          backgroundColor: Colors.black,
        ),
        backgroundColor: Colors.black,
        body: Padding(
          padding: const EdgeInsets.fromLTRB(10, 10, 10, 10),
          child: SingleChildScrollView(
            child: Column(
              children: [
                GestureDetector(
                    onTap: () {
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                          builder: (context) => const Academic(),
                        ),
                      );
                    },
                    child: Column(
                      children: [
                        Container(
                            decoration: BoxDecoration(
                              color: Colors.red,
                              borderRadius: BorderRadius.circular(10),
                              image: const DecorationImage(
                                image: NetworkImage(
                                    'https://img.freepik.com/free-vector/elegant-red-background_1340-4770.jpg?size=626&ext=jpg&ga=GA1.1.1387024122.1708704045&semt=sph'),
                                fit: BoxFit.cover,
                              ),
                            ),
                            height: 130,
                            width: 400,
                            child: const Center(
                              child: Text(
                                "Academic\nDetails",
                                style: TextStyle(
                                    fontSize: 33, color: Colors.white),
                              ),
                            )),
                        const SizedBox(
                          height: 15,
                        )
                      ],
                    )),
                GestureDetector(
                    onTap: () {
                      print("RE");
                    },
                    child: Column(
                      children: [
                        Container(
                            decoration: BoxDecoration(
                              color: Colors.blue,
                              borderRadius: BorderRadius.circular(10),
                              image: const DecorationImage(
                                  image: NetworkImage(
                                      'https://img.freepik.com/free-photo/abstract-grunge-decorative-relief-navy-blue-stucco-wall-texture-wide-angle-rough-colored-background_1258-28311.jpg?size=626&ext=jpg&ga=GA1.1.1387024122.1708704045&semt=sph'),
                                  fit: BoxFit.cover),
                            ),
                            height: 130,
                            width: 400,
                            child: const Center(
                              child: Text(
                                "Register &\nEvents",
                                style: TextStyle(
                                    fontSize: 33, color: Colors.white),
                              ),
                            )),
                        const SizedBox(
                          height: 10,
                        )
                      ],
                    )),
              ],
            ),
          ),
        ));
  }
}

class Academic extends StatelessWidget {
  const Academic({Key? key}) : super(key: key);

  Widget _buildGridItem({
    required IconData icon,
    required String title,
    required Color color,
    required VoidCallback onTap,
  }) {
    return GestureDetector(
      onTap: onTap,
      child: Column(
        children: [
          Container(
            decoration: BoxDecoration(
              color: color,
              borderRadius: BorderRadius.circular(10),
            ),
            height: 160,
            width: 160,
            padding: const EdgeInsets.fromLTRB(20, 37, 20, 20),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Icon(
                  icon,
                  color: color == Colors.white ? Colors.black : Colors.white,
                ),
                const SizedBox(height: 8),
                Text(
                  title,
                  style: TextStyle(
                    color: color == Colors.white ? Colors.black : Colors.white,
                    fontSize: 17,
                    fontWeight: FontWeight.w500,
                  ),
                ),
              ],
            ),
          ),
          const SizedBox(height: 25),
        ],
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.black,
        leading: IconButton(
          icon: const Icon(
            Icons.arrow_back,
            color: Colors.white,
          ),
          onPressed: () {
            Navigator.pop(
                context); // Navigate back to the previous route (Home)
          },
        ),
      ),
      backgroundColor: Colors.black,
      body: Padding(
        padding: const EdgeInsets.fromLTRB(25, 10, 25, 10),
        child: RefreshIndicator(
          onRefresh: () async {},
          child: SingleChildScrollView(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    const Text(
                      "Academic Dashboard",
                      style: TextStyle(
                          color: Colors.white,
                          fontSize: 20,
                          fontWeight: FontWeight.w500),
                    ),
                    IconButton(
                      icon: const Icon(
                        Icons.refresh_outlined,
                        color: Colors.white,
                      ),
                      onPressed: () {},
                    )
                  ],
                ),
                const SizedBox(
                  height: 40,
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    _buildGridItem(
                      icon: Icons.calendar_month_outlined,
                      title: 'View\nTimetable',
                      color: Colors.white,
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                            builder: (context) => const Timetable(),
                          ),
                        );
                      },
                    ),
                    _buildGridItem(
                      icon: Icons.check_box_outlined,
                      title: 'View\nAttendance',
                      color: const Color.fromARGB(255, 54, 51, 229),
                      onTap: () {},
                    ),
                  ],
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    _buildGridItem(
                      icon: Icons.check_box_outlined,
                      title: 'View\nInternal marks',
                      color: const Color.fromARGB(255, 54, 51, 229),
                      onTap: () {},
                    ),
                    _buildGridItem(
                      icon: Icons.score_outlined,
                      title: 'View\nCGPA history',
                      color: Colors.white,
                      onTap: () {},
                    ),
                  ],
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    _buildGridItem(
                      icon: Icons.calendar_month_outlined,
                      title: 'View\nCourses',
                      color: Colors.white,
                      onTap: () {},
                    ),
                    _buildGridItem(
                      icon: Icons.check_box_outlined,
                      title: 'View\nFee payments',
                      color: const Color.fromARGB(255, 54, 51, 229),
                      onTap: () {},
                    ),
                  ],
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    _buildGridItem(
                      icon: Icons.check_box_outlined,
                      title: 'View\nExam schedule',
                      color: const Color.fromARGB(255, 54, 51, 229),
                      onTap: () {},
                    ),
                    _buildGridItem(
                      icon: Icons.calendar_month_outlined,
                      title: 'View\nFee due',
                      color: Colors.white,
                      onTap: () {},
                    ),
                  ],
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}

class Timetable extends StatelessWidget {
  const Timetable({super.key});

  @override
  Widget build(BuildContext context) {
    return DefaultTabController(
      length: 6, // no tabs
      initialIndex: 0, // when open which tab should be showed
      child: Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.black,
          title: const Text(
            'Timetable',
            style: TextStyle(
                color: Colors.white, fontWeight: FontWeight.w500, fontSize: 18),
          ),
          leading: IconButton(
            icon: const Icon(
              Icons.arrow_back,
              color: Colors.white,
            ),
            onPressed: () {
              Navigator.pop(
                  context); // Navigate back to the previous route (Home)
            },
          ),
          bottom: PreferredSize(
            preferredSize:
                const Size.fromHeight(35), // Adjust the height of the TabBar
            child: SizedBox(
              height: 28, // to change the height of the tab indicator
              child: TabBar(
                padding: const EdgeInsets.only(left: 20, right: 20),
                dividerColor: Colors.black,
                indicatorSize: TabBarIndicatorSize.tab,
                indicator: BoxDecoration(
                  color: Colors.white,
                  borderRadius: BorderRadius.circular(5),
                ),
                labelColor: const Color.fromARGB(255, 34, 74, 250),
                unselectedLabelColor: Colors.grey,
                labelStyle:
                    const TextStyle(fontSize: 18, fontWeight: FontWeight.w500),
                unselectedLabelStyle:
                    const TextStyle(fontSize: 18, fontWeight: FontWeight.w500),
                labelPadding: const EdgeInsets.symmetric(
                    horizontal: 8), // prevent fading at end
                tabs: const [
                  Tab(text: 'MON'),
                  Tab(text: 'TUE'),
                  Tab(text: 'WED'),
                  Tab(text: 'THU'),
                  Tab(text: 'FRI'),
                  Tab(text: 'SAT'),
                ],
              ),
            ),
          ),
        ),
        backgroundColor: Colors.black,
        body: const TabBarView(
          children: [
            Scroll(),
            Scroll(),
            Scroll(),
            Scroll(),
            Scroll(),
            Scroll(),
          ],
        ),
      ),
    );
  }
}

class Scroll extends StatelessWidget {
  const Scroll({super.key});

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.only(top: 18),
      child: ListView(
        children: [
          for (int i = 0; i < 5; i++)
            Container(
              margin: const EdgeInsets.only(bottom: 18),
              height: 65,
              width: 350,
              decoration: BoxDecoration(
                color: Colors.white,
                borderRadius: BorderRadius.circular(5),
              ),
              padding: const EdgeInsets.only(
                  left: 15, top: 11, right: 13, bottom: 11),
              child: const Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        'SUBJECT NAME',
                        style: TextStyle(
                            color: Colors.black,
                            fontSize: 15,
                            fontWeight: FontWeight.w500),
                      ),
                      Text(
                        'Faculty Name',
                        style: TextStyle(color: Colors.grey),
                      )
                    ],
                  ),
                  Text(
                    'Time',
                    style: TextStyle(
                        color: Color.fromARGB(255, 34, 74, 250),
                        fontSize: 16,
                        fontWeight: FontWeight.w500),
                  ),
                ],
              ),
            ),
          for (int i = 0; i < 5; i++)
            Container(
              margin: const EdgeInsets.only(bottom: 18),
              height: 65,
              width: 350,
              decoration: BoxDecoration(
                color: const Color.fromARGB(255, 34, 74, 250),
                borderRadius: BorderRadius.circular(5),
              ),
              padding: const EdgeInsets.only(
                  left: 15, top: 11, right: 13, bottom: 11),
              child: const Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Text(
                    'FREE HOUR',
                    style: TextStyle(
                        color: Colors.white,
                        fontSize: 15,
                        fontWeight: FontWeight.w500),
                  ),
                  Text(
                    'Time',
                    style: TextStyle(
                        color: Colors.white,
                        fontSize: 16,
                        fontWeight: FontWeight.w500),
                  ),
                ],
              ),
            ),
        ],
      ),
    );
  }
}
