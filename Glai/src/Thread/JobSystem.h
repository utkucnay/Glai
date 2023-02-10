#pragma once
#include "Job.h"



namespace Glai::JobSystem
{
	class JobSystem
	{
	public:
		enum JobType
		{
			kAudio,
			kHigh,
			kPhysics,
			kLow,
			kIO,
			kDecompression
		};

	public:
		JobSystem() 
		{

		}

	public:
		void AddJob(Job* job, JobType jobType) {
			switch (jobType)
			{
			case kAudio:
				audioJobs.push_back(job);
				break;
			case kHigh:
				highJobs.push_back(job);
				break;
			case kPhysics:
				physicsJobs.push_back(job);
				break;
			case kLow:
				lowJobs.push_back(job);
				break;
			case kIO:
				ioJobs.push_back(job);
				break;
			case kDecompression:
				decompressionJobs.push_back(job);
				break;
			default:
				ENG_CORE_ASSERT("Undifened JobType")
					break;
			}
		}

	private:
		std::vector<Job*> audioJobs;
		std::vector<Job*> highJobs;
		std::vector<Job*> physicsJobs;
		std::vector<Job*> lowJobs;
		std::vector<Job*> ioJobs;
		std::vector<Job*> decompressionJobs;
	};
}