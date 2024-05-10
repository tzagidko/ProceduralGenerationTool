// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneratingTool.h"
#include "ProceduralMeshComponent.h"
#include "KismetProceduralMeshLibrary.h"

// Sets default values
AGeneratingTool::AGeneratingTool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	ProceduralMesh=CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMesh");
	ProceduralMesh->SetupAttachment(GetRootComponent());
	
}

// Called when the game starts or when spawned
void AGeneratingTool::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AGeneratingTool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGeneratingTool::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	Vertices.Reset();
	Triangles.Reset();
	UV0.Reset();
	
	CreateVertices();
	CreateTriangles();

	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UV0, Normals, Tangents);
	
	ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, Normals, UV0,
		TArray<FColor>(), Tangents, true);
	ProceduralMesh->SetMaterial(0, Material);
}

void AGeneratingTool::CreateVertices()
{
	for(int x=0;x<=XSize;++x)
	{
		for(int y=0; y<=YSize;++y)
		{
			float ValueZ=0;
			ValueZ=FMath::PerlinNoise2D(FVector2D((x*NoiseScale)+0.1,(y*NoiseScale)+0.1))*ZMultiplier;
			Vertices.Add(FVector(x*Scale,y*Scale,ValueZ));
			UV0.Add(FVector2D(x*UVScale,y*UVScale));

			//DrawDebugSphere(GetWorld(), FVector(x*Scale,y*Scale,0), 25.0f,16, FColor::Red,true, -1.0f,0U, 0.0f);
		}
	}
}

void AGeneratingTool::CreateTriangles()
{
	int Vertex=0;
	for(int i=0; i<XSize; ++i)
	{
		for(int j=0;j<YSize;++j)
		{
			Triangles.Add(Vertex);
			Triangles.Add(Vertex + 1);
			Triangles.Add(Vertex + YSize+1);
			Triangles.Add(Vertex +1);
			Triangles.Add(Vertex+YSize+2);
			Triangles.Add(Vertex+YSize+1);
			++Vertex;
		
		}
		++Vertex;
	}
	
	
}

