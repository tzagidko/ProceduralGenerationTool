// Fill out your copyright notice in the Description page of Project Settings.


#include "VoronoiGeneratorLibrary.h"


TArray<FVoronoiCell> UVoronoiGeneratorLibrary::GenerateVoronoiDiagram(const TArray<FVoronoiPoint>& Points, float MinX, float MaxX, float MinY, float MaxY)
{
	TArray<FVoronoiCell> Cells;

	TArray<FVector2D> InputPoints;
	for(const FVoronoiPoint&Point:Points)
	{
		InputPoints.Add(FVector2D(Point.X,Point.Y));
	}

	for(const FVector2D&Site:InputPoints)
	{
		FVoronoiCell Cell;
		Cell.Site.X=Site.X;
		Cell.Site.Y=Site.Y;

		for(float X=MinX; X<=MaxX;++X)
		{
			for(float Y=MinY; Y<=MaxY; ++Y)
			{
				FVector2D CurrentPoint(X,Y);

				float MinDistance=TNumericLimits<float>::Max();
				FVector2D NearestSite;
				for(const FVector2D&Point:InputPoints)
				{
					float between;
					between = CalculateDistance(CurrentPoint, Point);
					if(between<MinDistance)
					{
						MinDistance=between;
						NearestSite=Point;
					}
				}
				if(NearestSite.X==Site.X&& NearestSite.Y==Site.Y)
				{
					TArray<FVector2D> Neighbours={
						{X+1,Y}, {X-1, Y}, {X,Y+1}, {X,Y-1}
					};
					for(const FVector2D& Neighbour:Neighbours)
					{
						if(Neighbour.X>=MinX&&Neighbour.X<=MaxX&&Neighbour.Y>=MinY&&Neighbour.Y<=MaxY)
						{
							bool IsNeighbourSite = false;
							for(const FVector2D&Point: InputPoints)
							{
								if(Neighbour.X==Point.X &&Neighbour.Y==Point.Y)
								{
									IsNeighbourSite=true;
									break;
								}
							}
							if(!IsNeighbourSite)
							{
								FVoronoiLineSegment Segment;
								Segment.Start.X= CurrentPoint.X;
								Segment.Start.Y= CurrentPoint.Y;
								Segment.End.X=Neighbour.X;
								Segment.End.Y=Neighbour.Y;
								Cell.Edges.Add(Segment);
							}
						}
					}
				}
			}
		}
		Cells.Add(Cell);
	}

	return Cells;
}

float UVoronoiGeneratorLibrary::CalculateDistance(const FVector2D& Point1, const FVector2D& Point2)
{
	double Output;
	Output=FVector2D::Distance(Point1, Point2);
	return Output;
}






