// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateVoronoiDiagram.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGenerateVoronoiDiagram::AGenerateVoronoiDiagram()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AGenerateVoronoiDiagram::BeginPlay()
{
	Super::BeginPlay();
	GenerateDiagram();
	
}

void AGenerateVoronoiDiagram::GenerateDiagram()
{
	TArray<FVoronoiCell> VoronoiCells=UVoronoiGeneratorLibrary::GenerateVoronoiDiagram(VoronoiPoints, MinX, MaxX, MinY, MaxY);
	VisualizeVoronoiDiagram(VoronoiCells);
	
}

// Called every frame
void AGenerateVoronoiDiagram::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGenerateVoronoiDiagram::VisualizeVoronoiDiagram(const TArray<FVoronoiCell>& Cells)
{
	for(const FVoronoiCell&Cell:Cells)
	{
		for(const FVoronoiLineSegment&Edge:Cell.Edges)
		{
			DrawDebugLine(GetWorld(), FVector(Edge.Start.X, Edge.Start.Y, 0), FVector(Edge.End.X, Edge.End.Y, 0), FColor::Red, false, -1, 0, 2);
		}
	}
}

